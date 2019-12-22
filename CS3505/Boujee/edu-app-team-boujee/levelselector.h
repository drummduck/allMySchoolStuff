#ifndef LEVELSELECTOR_H
#define LEVELSELECTOR_H

#include <QWidget>
#include <QPushButton>
#include "level.h"

namespace Ui {
class levelSelector;
}

class levelSelector : public QWidget
{
    Q_OBJECT
    Ui::levelSelector *ui;

public:
    explicit levelSelector(QWidget *parent = 0);
    ~levelSelector();\
    void displayComponents();
    void hideComponents();
    QPushButton* getLevelOneButton();

public slots:
    void handleSignOutPressed();
signals:
    void signOut();

};

#endif // LEVELSELECTOR_H
