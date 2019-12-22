//Nathan Donaldson & Scott Neville
//A5: A Qt Stopwatch

//This is the header file for our Model, it creates all local variables, slots, and signals
//to be used in the cpp file. Includes whatever header files we need for the project.
#ifndef MODEL_H
#define MODEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTime>
#include <math.h>
#include <QTimer>
#include <iostream>
#include <string>


//Constructor for the Model class.
//Creates data members which keep track of time, text, and state of Model.
//Creates all signals and slots to be used for UI.
class Model : public QObject
{
    Q_OBJECT

//Member variables
public:
    QTime Time;
    QTimer* Timer;
    int Min, Sec, Ms, tempTime;
    bool Pause;
    QString Start_Pause_Restart_Text;
    explicit Model(QObject *parent = 0);

//Signals to fire to view
signals:
void Start_Pause_Restart_Data(QString);
void Reset_Data(QString);
void Min_Data(QString);
void Sec_Data(QString);
void Ms_Data(QString);

//Methods to use when button is pushed or on timout fire
public slots:
void UpdateTime();
void Start_Pause_Restart();
void Reset();

};

#endif // MODEL_H
