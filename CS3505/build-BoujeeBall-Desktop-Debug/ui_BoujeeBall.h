/********************************************************************************
** Form generated from reading UI file 'BoujeeBall.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOUJEEBALL_H
#define UI_BOUJEEBALL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoujeeBall
{
public:
    QAction *actionLogin;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *testLayout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BoujeeBall)
    {
        if (BoujeeBall->objectName().isEmpty())
            BoujeeBall->setObjectName(QString::fromUtf8("BoujeeBall"));
        BoujeeBall->resize(1019, 640);
        actionLogin = new QAction(BoujeeBall);
        actionLogin->setObjectName(QString::fromUtf8("actionLogin"));
        centralWidget = new QWidget(BoujeeBall);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        testLayout = new QVBoxLayout();
        testLayout->setSpacing(0);
        testLayout->setObjectName(QString::fromUtf8("testLayout"));

        gridLayout->addLayout(testLayout, 0, 0, 1, 1);

        BoujeeBall->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(BoujeeBall);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BoujeeBall->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BoujeeBall);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BoujeeBall->setStatusBar(statusBar);

        retranslateUi(BoujeeBall);

        QMetaObject::connectSlotsByName(BoujeeBall);
    } // setupUi

    void retranslateUi(QMainWindow *BoujeeBall)
    {
        BoujeeBall->setWindowTitle(QApplication::translate("BoujeeBall", "BoujeeBall", 0, QApplication::UnicodeUTF8));
        actionLogin->setText(QApplication::translate("BoujeeBall", "Login", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BoujeeBall: public Ui_BoujeeBall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOUJEEBALL_H
