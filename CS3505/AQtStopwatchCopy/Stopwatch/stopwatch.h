#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QMainWindow>
#include "model.h"
#include "ui_stopwatch.h"
#include <QTimer>
#include <QLCDNumber>


namespace Ui {
class Stopwatch;
}

class Stopwatch : public QMainWindow
{
    Q_OBJECT

public:
    Model model;
    explicit Stopwatch(QWidget *parent = 0);
    ~Stopwatch();

signals:


public slots:


private:
    Ui::Stopwatch *ui;
};


#endif // STOPWATCH_H
