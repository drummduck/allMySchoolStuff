#ifndef DRAWINGDEMO_H
#define DRAWINGDEMO_H

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class DrawingDemo;
}

class DrawingDemo : public QMainWindow
{
    Q_OBJECT

public:
    explicit DrawingDemo(QWidget *parent = 0);
    ~DrawingDemo();
    void valuesChanged();
    void paintEvent(QPaintEvent*);

private:
    Ui::DrawingDemo *ui;
};

#endif // DRAWINGDEMO_H
