/********************************************************************************
** Form generated from reading UI file 'levelselector.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELSELECTOR_H
#define UI_LEVELSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_levelSelector
{
public:
    QPushButton *signOutButton;

    void setupUi(QWidget *levelSelector)
    {
        if (levelSelector->objectName().isEmpty())
            levelSelector->setObjectName(QStringLiteral("levelSelector"));
        levelSelector->resize(1280, 720);
        signOutButton = new QPushButton(levelSelector);
        signOutButton->setObjectName(QStringLiteral("signOutButton"));
        signOutButton->setGeometry(QRect(20, 640, 85, 51));

        retranslateUi(levelSelector);

        QMetaObject::connectSlotsByName(levelSelector);
    } // setupUi

    void retranslateUi(QWidget *levelSelector)
    {
        levelSelector->setWindowTitle(QApplication::translate("levelSelector", "Form", 0));
        signOutButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class levelSelector: public Ui_levelSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELSELECTOR_H
