#include "boomchicka.h"
#include "ui_boomchicka.h"


boomchicka::boomchicka(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boomchicka)
{
    ui->setupUi(this);
}

boomchicka::~boomchicka()
{
    delete ui;
}
