#ifndef NETWORKMONITOR_H
#define NETWORKMONITOR_H

#include <QObject>
#include "SFML/Network.hpp"
#include "vector"
#include "QTimer"
#include "QMessageBox"
#include "sstream"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QFile>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <fstream>


class NetworkMonitor : public QObject
{
    Q_OBJECT

    // Open a listener on a port
    sf::TcpListener listener;
    // Talk over a TCP socket
    sf::TcpSocket client;
    bool connected;
    QNetworkAccessManager *manager;

public:
    explicit NetworkMonitor(QObject *parent = 0);
    void handleUpdateLastLevel(std::string username, int newLastLevel);
    void handleAttemptLogin(std::string username, std::string password, bool admin);
    void handleDeleteUser(std::string username);
    std::vector<std::string> parseWords(std::string s);
    void handleUpdateAnaltics(bool sendBack);


signals:
    std::string updateCurrentUser(std::string newUser);
    int updateCurrentLevel(int newLevel);
    std::string updateNotification(std::string error);
    void accessGranted();
    void accessDenied();
    void errorMessageFromServer(std::string msg);
    void openUpWebpage();

public slots:
    void generateHtml(std::string);
    void getResponse();
    void handleFacebookShare(QByteArray message, QString filename);
    void handleTeacherCreate(std::string username, std::string password);
    void finishedFacebook(QNetworkReply *reply);
    void resetListener();

};

#endif // NETWORKMONITOR_H
