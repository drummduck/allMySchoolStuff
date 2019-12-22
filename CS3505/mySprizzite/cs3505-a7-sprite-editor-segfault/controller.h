/****
 * controller.h
 *
 * The brains behind everything. The Controller is responsible for relaying
 * information between the View and the Model.
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QColor>
#include <QPoint>
#include <QPointF>

class MainWindow;
typedef QPoint CellAddress;
typedef QPointF ViewPoint;

// Tools
namespace Tools {
    enum tool {
        Pencil,
        Eraser,
        MirrorPencil,
        MirrorEraser
    };
}

class Controller
{
public:
    // Constructors
    Controller();
    Controller(MainWindow* main_window);
    Controller(MainWindow* main_window, int user_dimension);

    // Drawing and tools.
    void setActiveColor(QColor color);
    void setForegroundColor(QColor color);
    // Attributes.
private:
    QColor active_color;
    //QColor active_color_2;
    // Save and Load methods.
};

#endif
