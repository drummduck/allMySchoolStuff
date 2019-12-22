#include "networkmonitor.h"

NetworkMonitor::NetworkMonitor(QObject *parent) : QObject(parent)
{
    //Set up server.
    connected = false;
    // The TCP socket should be non-blocking to keep the GUI from hanging
    client.setBlocking(false);
    //listener.setBlocking(false);
    listener.listen(53003);
}



void NetworkMonitor::handleUpdateLastLevel(std::string username, int newLastLevel){
    //Hit the servers line.
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("localhost", 53001);

    //If there was an error.
    if(status == sf::Socket::Status::Error){
        QMessageBox msg;
        msg.setParent(0);
        msg.setWindowFlags(Qt::FramelessWindowHint);
        msg.setText("<center>Error on update last level. Make sure you are connected to the server.</center>");
        msg.exec();
        return;
    }
    //Parse int to string.
    std::stringstream ss;
    ss << newLastLevel;
    std::string str = ss.str();

    //Generate packet and send it.
    sf::Packet outPacket;\
    outPacket << std::string("update_user_level ") + username
                 + std::string(" ") + str;
    socket.send(outPacket);
}

void NetworkMonitor::handleUpdateAnaltics(bool sendBack){
    //Hit the servers line.
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("localhost", 53001);

    //If there was an error.
    if(status == sf::Socket::Status::Error){
        QMessageBox msg;
        msg.setParent(0);
        msg.setWindowFlags(Qt::FramelessWindowHint);
        msg.setText("<center>Error updating Analytics. Not connected to server.</center>");
        msg.exec();
        return;
    }

    sf::Packet outPacket;
    outPacket << std::string("update_analytics");
    socket.send(outPacket);

    if(sendBack){
        QTimer::singleShot(100, this, SLOT(getResponse()));
        //log->disableLogin();
        listener.accept(client);
    }
}

/**
 * @brief BoujeeBall::handleAttempLogin
 * This sends username and password to database
 * @param username
 * Username of intended sign in.
 * @param password
 * Pasword associated with that user.
 */
void NetworkMonitor::handleAttemptLogin(std::string username, std::string passwords, bool admin){
    //Hit the servers line.
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("localhost", 53001);

    //If there was an error.
    if(status == sf::Socket::Status::Error){
        QMessageBox msg;
        msg.setWindowFlags(Qt::FramelessWindowHint);
        msg.setParent(0);
        msg.setText("<center>Error on login/creation. Make sure your connected to the server.</center>");
        msg.exec();
        return;
    }

    sf::Packet outPacket;
    outPacket << std::string("create_user ") + username
                 + std::string(" ") + passwords;
    socket.send(outPacket);
    if(!admin){
        QTimer::singleShot(100, this, SLOT(getResponse()));
        //log->disableLogin();
        listener.accept(client);
    }
}

void NetworkMonitor::handleDeleteUser(std::string username){
    //Hit the servers line.
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("localhost", 53001);

    //If there was an error.
    if(status == sf::Socket::Status::Error){
        QMessageBox msg;
        msg.setParent(0);
        msg.setWindowFlags(Qt::FramelessWindowHint);
        msg.setText("<center>Error on deletion. Make sure  you are connected to server.</center>");
        msg.exec();
        return;
    }

    sf::Packet outPacket;
    outPacket << std::string("delete_user ") + username;
    socket.send(outPacket);
}

/**
 * @brief BoujeeBall::getResponse
 * This method gets the reponse from the server for any message we send to it.
 */
void NetworkMonitor::getResponse(){
    sf::Packet packet;
    //QApplication::flush();
    if (client.receive(packet) == sf::Socket::Done)
    {
        // The client has sent some data, we can receive it
        std::string msg;
        packet >> msg;
        std::vector<std::string> msgWords = this->parseWords(msg);
        if(msgWords.at(0) == "success_creating_user"){
            //On creating_user_success;
            //Sets up new values for current user.
            emit updateCurrentUser(msgWords.at(1)); //this->currentUser = QString::fromStdString(msgWords.at(1));
            emit updateCurrentLevel(std::atoi(msgWords.at(2).c_str())); //this->lastLevel = std::atoi(msgWords.at(2).c_str());

            //Sends user to the next screen.
            emit updateNotification("Login successful"); //log->setNotification("Login successful");
            emit accessGranted(); //emit selectMode();

            //Disconnects the client.
            client.disconnect();
            return;
        }else if(msgWords.at(0) == "error_creating_user"){
            emit accessDenied();\
            emit errorMessageFromServer("Login failed please try again.");
        }else if(msgWords.at(0) == "error_login_user"){
            emit accessDenied();
            emit errorMessageFromServer("Login failed bad password please try again.");
        }else if(msgWords.at(0) == "succes_delete_user"){
            emit errorMessageFromServer("Succes deleting user");
        }else if(msgWords.at(0) == "ANALYTICS"){
            this->generateHtml(msgWords.at(1));
        }
    }
    // Use a timer to keep checking for packets while keeping the GUI alive
    QTimer::singleShot(100, this, SLOT(getResponse()));
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
std::vector<std::string> NetworkMonitor::parseWords(std::string s){
    std::vector<std::string> returnVector;
    std::istringstream buf(s);
    for(std::string word; buf >> word;){
        returnVector.push_back(word);
        if(word == "ANALYTICS"){
            returnVector.push_back(s);
            break;
        }
    }
    return returnVector;
}

/**
 * @brief handleFacebookShare
 *
 * This slot is called when the user clicks on the Facebook share button.
 * Two pieces of information are required to use this feature:
 *
 * 1. an access token with publish_actions, user_posts, and user_photos enabled
 * 2. a Facebook userid
 *
 * You can generate an access token and find your Facebook userid by going to
 * https://developers.facebook.com/tools/explorer/ and clicking on
 * Get Token -> Get User Acess Token -> enable publish_actions & user_posts.
 *
 * When you generate an access token your userid and name are returned. Your userid
 * is the value to "id" key.
 *
 * As soon as you have your userid and an access token, copy and paste them
 * into the variables below and you're ready to use the share to facebook feature.
 *
 */
void NetworkMonitor::handleFacebookShare(QByteArray message, QString filename){

    // assign accessToken and userid here
    QByteArray accessToken = "EAACEdEose0cBALWRHlUMW5ivtluvwHeJr9k7ZAPjVfa52yVOPZABIJs0vj5ZCt5f8ZBdpN7kROiEcDUVLplHT4j2O733kQkeH6lAGybggsLy826YkQCxLBwJ65q58ZCqZAZBLof2pAIND1iEBnXeETfAbrx67nkV3ulqjwvB2IbngZDZD";
    QByteArray userid = "10200253962307485";

    // check out https://developers.facebook.com/docs/graph-api/photo-uploads to see the documentation

    // create new multipart object and set random boundary string
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    multiPart->setBoundary("---boundary9584736284kdjse28DJKLEikfj284");
\
    // create the acccess part (access token)
    QHttpPart accessPart;
    accessPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"access_token\""));
    accessPart.setBody(accessToken);

    // create the text part (caption)
    QHttpPart textPart;
    textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"caption\""));
    textPart.setBody(message);

    // create the image part (image to upload)
    QHttpPart imagePart;
    imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"image\"; filename=\"filenamehere\""));
    // create the file to be uploaded
    QFile *file = new QFile(filename);

    file->open(QIODevice::ReadOnly);
    // attach file to imagePart
    imagePart.setBodyDevice(file);
    // delete file with the multiPart
    file->setParent(multiPart);

    multiPart->append(accessPart);
    multiPart->append(textPart);
    multiPart->append(imagePart);


    QUrl url("https://graph.facebook.com/v2.8/"+userid+"/photos");
    // create request using the url
    QNetworkRequest request(url);
    manager = new QNetworkAccessManager(this);

    // post the image and delete multiPart with the reply
    QNetworkReply *reply = manager->post(request, multiPart);
    multiPart->setParent(reply);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedFacebook(QNetworkReply*)));
}

/**
 * @brief NetworkMonitor::finishedFacebook
 * @param reply
 *
 * This is the response handler for the call to
 * postURLToFacebook. Displays a messagebox to the
 * user upon completion.
 */
void NetworkMonitor::finishedFacebook(QNetworkReply *reply){
    // check for error
    if (reply->error()) {
        QString message = reply->errorString();

        //std::cout << message.toStdString() << std::endl;
        QMessageBox msg;
        msg.setParent(0);
        msg.setWindowFlags(Qt::FramelessWindowHint);
        msg.setText("<center>Sorry, unable to share score to your Facebook account. Bad access token perhaps?</center>");
        msg.exec();

    } else {
        // we got a response
        QString jsonString = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(jsonString.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();

        QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        int status = statusCode.toInt();

        QMessageBox msg;
        msg.setParent(0);
        msg.setWindowFlags(Qt::FramelessWindowHint);

        // we need to change this if to check for an unsuccesfful response
        if (status != 200) {
            msg.setText("<center>Sorry, unable to share score to your Facebook account. Bad access token perhaps?</center>");
            //msg.exec();
        } else {
            msg.setText("<center>Successfully shared your score to Facebook.</center>");
            msg.exec();
        }
    }

    delete manager;
}

void NetworkMonitor::resetListener()
{
    listener.listen(53003);
}


void NetworkMonitor::generateHtml(std::string htmlString){

    htmlString = htmlString.erase(0,9);
    std::size_t pos = htmlString.find("</table>");
    int size = htmlString.size();
    int tablePos = pos;
    htmlString = htmlString.erase(tablePos,size);
    std::ofstream html;
    html.open ("../edu-app-team-boujee/analytics.html");
    html << htmlString;
    html.close();
    emit openUpWebpage();
}

void NetworkMonitor::handleTeacherCreate(std::string username, std::string password){
    //Hit the servers line.
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("localhost", 53001);

    //If there was an error.
    if(status == sf::Socket::Status::Error){
        QMessageBox msg;
        msg.setWindowFlags(Qt::FramelessWindowHint);
        msg.setParent(0);
        msg.setText("<center>Error on login. Make sure your connected to the server.</center>");
        msg.exec();
        return;
    }

    sf::Packet outPacket;
    outPacket << std::string("teacher_create ") + username
                 + std::string(" ") + password;
    socket.send(outPacket);
}
