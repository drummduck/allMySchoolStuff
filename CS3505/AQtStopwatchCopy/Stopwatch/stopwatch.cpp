#include "stopwatch.h"
#include "QTimer"
#include <QLCDNumber>

Stopwatch::Stopwatch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stopwatch)
{
    ui->setupUi(this);

    ui->Minutes->display("00");
    ui->Seconds->display("00");
    ui->Milliseconds->display("00");

  //Start_Pause_Restart

    //Calls Start_Pause_Restart in model
    QObject::connect(ui->Start_Pause_Restart, &QPushButton::pressed,
                     &model, &Model::Start_Pause_Restart);

    //Updates Start_Pause_Restart text
    QObject::connect(&model, &Model::Start_Pause_Restart_Data,
                     ui->Start_Pause_Restart, &QPushButton::setText);

  //Reset

    //Calls Reset in model
    QObject::connect(ui->Reset, &QPushButton::pressed,
                     &model, &Model::Reset);

    //Updates Reset text
    QObject::connect(&model, &Model::Reset_Data,
                     ui->Start_Pause_Restart, &QPushButton::setText);



  //Minute update
    QObject::connect(&model, &Model::Min_Data,
                    ui->Minutes, (void (QLCDNumber::*)(const QString&))(&QLCDNumber::display));

 //Second update
    QObject::connect(&model, &Model::Sec_Data,
                    ui->Seconds, (void (QLCDNumber::*)(const QString&))(&QLCDNumber::display));


 //Millisecond update
    QObject::connect(&model, &Model::Ms_Data,
                    ui->Milliseconds, (void (QLCDNumber::*)(const QString&))(&QLCDNumber::display));


}

Stopwatch::~Stopwatch()
{
    delete ui;
}
