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
#include <sstream>

class Model : public QObject
{

    Q_OBJECT

public:
    QTime Time;
    QTimer* Timer;
    int Min, Sec, Ms, tempTime;
    bool Pause;
    QString Start_Pause_Restart_Text;
    explicit Model(QObject *parent = 0);

signals:
void Start_Pause_Restart_Data(QString);
void Reset_Data(QString);
void Min_Data(QString);
void Sec_Data(QString);
void Ms_Data(QString);


public slots:
void UpdateTime();
void Start_Pause_Restart();
void Reset();

};

#endif // MODEL_H
