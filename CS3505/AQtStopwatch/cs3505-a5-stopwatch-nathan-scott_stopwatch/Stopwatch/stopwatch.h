//Nathan Donaldson & Scott Neville
//A5: A Qt Stopwatch

//This is the header file for the stopwatch, it sets up a link to the UI
//and whatever .h files and libraries we need.
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

private:
    Ui::Stopwatch *ui;
};

#endif // STOPWATCH_H
