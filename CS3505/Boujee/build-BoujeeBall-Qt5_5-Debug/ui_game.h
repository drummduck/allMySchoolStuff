/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QLCDNumber *lcdNumber;
    QDoubleSpinBox *magnitude;
    QDoubleSpinBox *angle;
    QDoubleSpinBox *gravity;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QStringLiteral("Game"));
        Game->resize(1257, 653);
        lcdNumber = new QLCDNumber(Game);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(1180, 10, 64, 23));
        lcdNumber->setLayoutDirection(Qt::LeftToRight);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        magnitude = new QDoubleSpinBox(Game);
        magnitude->setObjectName(QStringLiteral("magnitude"));
        magnitude->setGeometry(QRect(180, 600, 68, 25));
        angle = new QDoubleSpinBox(Game);
        angle->setObjectName(QStringLiteral("angle"));
        angle->setGeometry(QRect(180, 630, 68, 25));
        angle->setMinimum(-90);
        angle->setMaximum(90);
        gravity = new QDoubleSpinBox(Game);
        gravity->setObjectName(QStringLiteral("gravity"));
        gravity->setGeometry(QRect(180, 570, 68, 25));
        gravity->setMinimum(-99.9);
        gravity->setSingleStep(0.1);
        gravity->setValue(0);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
