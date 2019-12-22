#include <QCoreApplication>
#include <bbserver.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BBServer server;
    server.setupConnection();

    return a.exec();
}
