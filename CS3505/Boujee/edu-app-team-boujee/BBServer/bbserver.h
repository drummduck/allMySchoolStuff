#ifndef BBSERVER_H
#define BBSERVER_H
#include <SFML/Network.hpp>
#include <iostream>
#include <QTimer>
#include <QObject>
#include <vector>
#include <sstream>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <QtSql>
#include "sstream"
#include <iostream>
#include <fstream>


/**
 * @brief The BBServer class
 * Glorious BoujeeBall server class.
 */
class BBServer : public QObject
{
    Q_OBJECT
public:
    explicit BBServer(QObject *parent = 0);
    ~BBServer();
    void setupConnection();
    void closeConnection();
    void createUser(std::string username, std::string password);
    void loginUser(std::string username, std::string password);
    void updateUserLevel(std::string username, std::string newLastLevel);
    void deleteUser(std::string username);
    void generateHTML();

private slots:
    void getPackets();

private:
    // Open a listener on a port
    sf::TcpListener listener;
    // Talk over a TCP socket
    sf::TcpSocket client;
    bool connected;
    std::vector<std::string> parseWords(std::string s);
    bool createUserDB(std::string username, std::string password, int& lastlevel, int& error);
};


#endif // BBSERVER_H
