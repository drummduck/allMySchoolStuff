#ifndef BOOMCHICKA_H
#define BOOMCHICKA_H

#include <QMainWindow>

namespace Ui {
class boomchicka;
}

class boomchicka : public QMainWindow
{
    Q_OBJECT

public:
    explicit boomchicka(QWidget *parent = 0);
    ~boomchicka();

private:
    Ui::boomchicka *ui;
};

#endif // BOOMCHICKA_H
