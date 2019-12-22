//Nathan Donaldson & Scott Neville
//A5: A Qt Stopwatch

//This is main, it starts the application
#include "stopwatch.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Stopwatch w;
    w.show();

    return a.exec();
}
