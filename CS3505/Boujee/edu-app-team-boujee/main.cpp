#include "BoujeeBall.h"
#include <QApplication>

int main(int argc, char *argv[])
{    
    QApplication App(argc, argv);

    BoujeeBall boujeeBallWindow;

    int x=1280;
    int y=720;
    boujeeBallWindow.setFixedSize(x,y);

    boujeeBallWindow.show();

    return App.exec();
}
