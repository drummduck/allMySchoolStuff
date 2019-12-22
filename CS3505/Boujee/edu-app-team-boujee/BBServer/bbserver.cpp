#include "bbserver.h"

/**
 * @brief BBServer::BBServer
 * Sets up the server to start lisenting for messages.
 * @param parent
 */
BBServer::BBServer(QObject *parent) : QObject(parent)
{
    connected = false;
    // The TCP socket should be non-blocking to keep the GUI from hanging
    client.setBlocking(false);
    listener.listen(53001);

}

BBServer::~BBServer()
{
    client.disconnect();
}

/**
 * @brief BBServer::setupConnection
 * When we need to wait for a new connection.
 */
void BBServer::setupConnection() {
    std::cout << "Waiting for client" << std::endl;
    listener.accept(client);
    std::cout << "Connected to client" << std::endl;
    // Start checking for packets
    QTimer::singleShot(100, this, SLOT(getPackets()));

}

void BBServer::closeConnection() {
    std::cout << "Disconnecting " << std::endl;
    client.disconnect();

}

/**
 * @brief BBServer::getPackets
 * Main message handler. Recieves messages and routes them to there
 * specified methods.
 */
void BBServer::getPackets() {
    sf::Packet packet;
    if (client.receive(packet) == sf::Socket::Done)
    {
        // The client has sent some data, we can receive it
        std::string msg;
        packet >> msg;
        if(msg.size() > 0){
            //Get the values out of the packet.
            std::vector<std::string> wordList = this->parseWords(msg);
            //If it is a create_user command call creatUser and start listening again.
            if(wordList.at(0) == "create_user"){
                createUser(wordList.at(1),wordList.at(2));
                std::cout << "Msg received: " << msg << std::endl;
                listener.accept(client);
                QTimer::singleShot(100, this, SLOT(getPackets()));
                return;
            //If it is a login_user call loginUser and start listening again.
            }else if(wordList.at(0) == "update_user_level"){
                updateUserLevel(wordList.at(1),wordList.at(2));
                std::cout << "Msg recieved: " << msg << std::endl;
                listener.accept(client);
                QTimer::singleShot(100, this, SLOT(getPackets()));
                return;
            }else if(wordList.at(0) == "delete_user"){
                deleteUser(wordList.at(1));
                std::cout << "Msg recieved: " << msg << std::endl;
                listener.accept(client);
                QTimer::singleShot(100, this, SLOT(getPackets()));
                return;
            }else if(wordList.at(0) == "update_analytics"){
                this->generateHTML();
                std::cout << "Msg recieved: " << "Open Analytics" << std::endl;
                listener.accept(client);
                QTimer::singleShot(100, this, SLOT(getPackets()));
                return;
            }else if(wordList.at(0) == "teacher_create"){
                int error, lastLevel;
                this->createUserDB(wordList.at(1),wordList.at(2),lastLevel,error);
                listener.accept(client);
                QTimer::singleShot(100, this, SLOT(getPackets()));
                return;

            }
            std::cout << "Msg received: " << msg << std::endl;
        }
    }
    // Use a timer to keep checking for packets while keeping the GUI alive
    QTimer::singleShot(100, this, SLOT(getPackets()));

}

/**
 * @brief BBServer:createUser
 * Method for handling a create user request. Will either return a positive
 * response or let the client know that the password was incorrect.
 * @param username
 * @param password
 */
void BBServer::createUser(std::string username, std::string password){
    //std::cout << "In create user" << std::endl;
    int lastlevel;
    int error;
    if(createUserDB(username,password,lastlevel,error)){
        //On success send success packet.
        sf::Packet outPacket;
        sf::TcpSocket socket;
        sf::Socket::Status status = socket.connect("localhost", 53003);
        std::stringstream ss;
        ss << "success_creating_user" << " " << username << " " << lastlevel;
        outPacket << ss.str();
        socket.send(outPacket);
    }else if(error == 1){
        sf::Packet outPacket;
        sf::TcpSocket socket;
        sf::Socket::Status status = socket.connect("localhost", 53003);
        std::string packet = std::string("error_login_user ") + username;
        outPacket << packet;
        socket.send(outPacket);
    }
    else{
        sf::Packet outPacket;
        sf::TcpSocket socket;
        sf::Socket::Status status = socket.connect("localhost", 53003);
        std::string packet = std::string("error_creating_user ") + username;
        outPacket << packet;
        socket.send(outPacket);
    }
}

/**
 * @brief BBServer::loginUser
 * Method for logining in a user.
 * @param username
 * @param password
 */
void BBServer::loginUser(std::string username, std::string password){
    //Check if the user is in the database and username and password matches.
    //If success.
    sf::Packet outPacket;
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("localhost", 53003);
    outPacket << std::string("success_on_login ") + username;
    socket.send(outPacket);
}

/**
 * @brief BBServer::updateUserLevel
 * Used to update the current users level.
 * @param username
 * User to update.
 * @param newLastLevel
 * new level for the user.
 */
void BBServer::updateUserLevel(std::string username, std::string newLastLevel){
    sql::Driver *driver;
    sql::Connection *connection;

    // get mysql driver and connect to db
    driver = get_driver_instance();
    connection = driver->connect("tcp://dboujee.cjdplm3h3qzc.us-west-2.rds.amazonaws.com:3306", "groupuser", "groupuserpass");

    // check connection
    if (connection->isValid()) {
        connection->setSchema("boujee");

        // prepare insert using username and password as placeholder values
        sql::PreparedStatement *updateStmt;
        updateStmt = connection->prepareStatement("update users set last_level=? where username=?");
        updateStmt->setInt(1, std::atoi(newLastLevel.c_str()));
        updateStmt->setString(2, username);
        // execute update
        updateStmt->execute();
    }

    // we also need to delete driver but it wasn't letting me
    delete connection;
}

/**
 * @brief BBServer::parseWords
 * This method takes a string of words, and returns
 * a vector of each of the words that made up that sentence.
 * @param s
 * Original string.
 * @return
 * Vector of strings.
 */
std::vector<std::string> BBServer::parseWords(std::string s){
    std::vector<std::string> returnVector;
    std::istringstream buf(s);
    for(std::string word; buf >> word;){
        returnVector.push_back(word);
    }
    return returnVector;
}


/**
 * @brief BBServer::createUserDB
 * Method that actual does the work in the database. If the username given is already int he database
 * will compare the password given to password in database. If it is wrong will return an error.
 * If it matches will send request to the client.
 *
 * If no user was in the database it will then create a new user in the database with given password.
 * @param username
 * @param password
 * @param lastlevel
 * @param error
 * @return
 */
bool BBServer::createUserDB(std::string username, std::string password, int& lastlevel, int& error){
    sql::Driver *driver;
    sql::Connection *connection;

    // get mysql driver and connect to db
    driver = get_driver_instance();
    connection = driver->connect("tcp://dboujee.cjdplm3h3qzc.us-west-2.rds.amazonaws.com:3306", "groupuser", "groupuserpass");

    // check connection
    if (connection->isValid()) {
        connection->setSchema("boujee");


        // prepare select using username as placeholder value
        sql::PreparedStatement *selectStmts;
        selectStmts = connection->prepareStatement("select user_id, last_level, password from users where username=?");
        selectStmts->setString(1, username);

        // get user_id
        sql::ResultSet *resultss;
        resultss = selectStmts->executeQuery();

        //If the user was in the database check password.
        int num = resultss->rowsCount();
        if(num == 1){
            while(resultss->next()) {
                int userid = resultss->getInt(1);
                lastlevel = resultss->getInt(2);
                std::string user_password = resultss->getString(3);

                if(user_password != password){
                    error=1;
                    return false;
                }
                delete selectStmts, resultss;
                std::cout << "User id: " << userid << "  Last level: " << lastlevel << std::endl;
                return true;
            }
        }


        // prepare insert using username and password as placeholder values
        sql::PreparedStatement *insertStmt;
        insertStmt = connection->prepareStatement("insert into users (username, password) values (?, ?) on duplicate key update username=?");
        insertStmt->setString(1, username);
        insertStmt->setString(2, password);
        insertStmt->setString(3, username);
        // execute insert
        insertStmt->execute();

        // prepare select using username as placeholder value
        sql::PreparedStatement *selectStmt;
        selectStmt = connection->prepareStatement("select user_id, last_level from users where username=?");
        selectStmt->setString(1, username);

        // get user_id
        sql::ResultSet *results;
        results = selectStmt->executeQuery();

        // take a look at results
        while(results->next()) {
            int userid = results->getInt(1);
            lastlevel = results->getInt(2);

            //std::cout << "User id: " << userid << "  Last level: " << lastlevel << std::endl;
        }

        delete insertStmt, selectStmt, results;

    }

    // we also need to delete driver but it wasn't letting me
    delete connection;
    return true;
}

/**
 * @brief BBServer::deleteUser
 * Sql for deleting a user from the database.
 * @param username
 * user to delete.
 */
void BBServer::deleteUser(std::string username){
    sql::Driver *driver;
    sql::Connection *connection;

    // get mysql driver and connect to db
    driver = get_driver_instance();
    connection = driver->connect("tcp://dboujee.cjdplm3h3qzc.us-west-2.rds.amazonaws.com:3306", "groupuser", "groupuserpass");

    // check connection
    if (connection->isValid()) {
        connection->setSchema("boujee");

        // prepare insert using username and password as placeholder values
        sql::PreparedStatement *deleteStmt;
        deleteStmt = connection->prepareStatement("delete from users where username=?");
        deleteStmt->setString(1, username);
        // execute update
        deleteStmt->execute();
    }

    // we also need to delete driver but it wasn't letting me
    delete connection;
}

/**
 * @brief BBServer::generateHTML
 * Method that makes the html for the teacher admin to view.
 */
void BBServer::generateHTML() {
    sql::Driver *driver;
    sql::Connection *connection;

    std::stringstream html;
    sf::Packet htmlPacket;
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("localhost", 53003);
    html << "ANALYTICS ";
    html << "<h1>Welcome to Boujee Ball Admin Page!</h1>";
    html <<"<p>Below is a table of all the usernames, passwords, level progress,and if the player has complete Boujee Ball.</p>";
    html << "<table dir=\"ltr\" width=\"500\" border=\"1\">";
    html << "<tr>";
    html << "<th id=\"c1\">Username</th>";
    html << "<th id=\"c2\">Password</th>";
    html << "<th id=\"c3\">Current level</th>";
    html << "<th id=\"c4\">Completed</th>";
    html << "</tr>";
    // get mysql driver and connect to db
    driver = get_driver_instance();
    connection = driver->connect("tcp://dboujee.cjdplm3h3qzc.us-west-2.rds.amazonaws.com:3306", "groupuser", "groupuserpass");

    // check connection
    if (connection->isValid()) {
        connection->setSchema("boujee");


        // prepare select using username as placeholder value
        sql::PreparedStatement *selectStmts;
        selectStmts = connection->prepareStatement("select username, password, last_level from users");

        // get user_id
        sql::ResultSet *results;
        results = selectStmts->executeQuery();
        while(results->next()) {
            std::string username = results->getString(1);
            std::string password = results->getString(2);
            int last_level = results->getInt(3);

            html << "<tr>";
            html << "<td headers=\"c1\">" << username << "</td>";
            html << "<td headers=\"c2\">" << password << "</td>";
            std::string completed;
            if (last_level > 6){
                completed = "True";
                last_level = 6;
            }else{
                completed = "False";
            }
            html << "<td headers=\"c3\">" << last_level << "</td>";
            html << "<td headers=\"c4\">" << completed << "</td>";
            html << "</tr>";
        }
        html << "</table>";

        delete selectStmts, results;
        htmlPacket << html.str();
        socket.send(htmlPacket);
        delete connection;
    }
}
