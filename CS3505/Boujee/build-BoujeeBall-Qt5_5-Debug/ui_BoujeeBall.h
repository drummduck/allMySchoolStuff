/********************************************************************************
** Form generated from reading UI file 'BoujeeBall.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOUJEEBALL_H
#define UI_BOUJEEBALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoujeeBall
{
public:
    QAction *actionLogin;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *widgetLayout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BoujeeBall)
    {
        if (BoujeeBall->objectName().isEmpty())
            BoujeeBall->setObjectName(QStringLiteral("BoujeeBall"));
        BoujeeBall->resize(1019, 777);
        actionLogin = new QAction(BoujeeBall);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        centralWidget = new QWidget(BoujeeBall);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widgetLayout = new QVBoxLayout();
        widgetLayout->setSpacing(0);
        widgetLayout->setObjectName(QStringLiteral("widgetLayout"));

        gridLayout->addLayout(widgetLayout, 0, 0, 1, 1);

        BoujeeBall->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BoujeeBall);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BoujeeBall->setStatusBar(statusBar);

        retranslateUi(BoujeeBall);

        QMetaObject::connectSlotsByName(BoujeeBall);
    } // setupUi

    void retranslateUi(QMainWindow *BoujeeBall)
    {
        BoujeeBall->setWindowTitle(QApplication::translate("BoujeeBall", "BoujeeBall", 0));
        actionLogin->setText(QApplication::translate("BoujeeBall", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class BoujeeBall: public Ui_BoujeeBall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOUJEEBALL_H
