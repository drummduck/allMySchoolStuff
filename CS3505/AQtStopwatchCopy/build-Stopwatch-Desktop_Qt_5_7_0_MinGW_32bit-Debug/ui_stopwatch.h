/********************************************************************************
** Form generated from reading UI file 'stopwatch.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOPWATCH_H
#define UI_STOPWATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stopwatch
{
public:
    QWidget *centralWidget;
    QPushButton *Start_Pause_Restart;
    QPushButton *Reset;
    QLCDNumber *Minutes;
    QLCDNumber *Seconds;
    QLCDNumber *Milliseconds;
    QTextEdit *Colone_One;
    QTextEdit *Colon_2;

    void setupUi(QMainWindow *Stopwatch)
    {
        if (Stopwatch->objectName().isEmpty())
            Stopwatch->setObjectName(QStringLiteral("Stopwatch"));
        Stopwatch->setEnabled(true);
        Stopwatch->resize(401, 218);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Stopwatch->sizePolicy().hasHeightForWidth());
        Stopwatch->setSizePolicy(sizePolicy);
        Stopwatch->setMinimumSize(QSize(401, 218));
        Stopwatch->setMaximumSize(QSize(401, 218));
        Stopwatch->setContextMenuPolicy(Qt::DefaultContextMenu);
        Stopwatch->setToolButtonStyle(Qt::ToolButtonIconOnly);
        Stopwatch->setAnimated(false);
        Stopwatch->setTabShape(QTabWidget::Rounded);
        Stopwatch->setDockNestingEnabled(false);
        Stopwatch->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(Stopwatch);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Start_Pause_Restart = new QPushButton(centralWidget);
        Start_Pause_Restart->setObjectName(QStringLiteral("Start_Pause_Restart"));
        Start_Pause_Restart->setGeometry(QRect(60, 140, 101, 41));
        Start_Pause_Restart->setContextMenuPolicy(Qt::DefaultContextMenu);
        Start_Pause_Restart->setStyleSheet(QStringLiteral(""));
        Start_Pause_Restart->setCheckable(true);
        Start_Pause_Restart->setChecked(false);
        Start_Pause_Restart->setFlat(false);
        Reset = new QPushButton(centralWidget);
        Reset->setObjectName(QStringLiteral("Reset"));
        Reset->setGeometry(QRect(240, 140, 101, 41));
        Minutes = new QLCDNumber(centralWidget);
        Minutes->setObjectName(QStringLiteral("Minutes"));
        Minutes->setGeometry(QRect(80, 30, 61, 61));
        Minutes->setFrameShape(QFrame::NoFrame);
        Minutes->setFrameShadow(QFrame::Plain);
        Minutes->setSmallDecimalPoint(false);
        Minutes->setDigitCount(2);
        Minutes->setMode(QLCDNumber::Dec);
        Minutes->setSegmentStyle(QLCDNumber::Flat);
        Minutes->setProperty("value", QVariant(0));
        Seconds = new QLCDNumber(centralWidget);
        Seconds->setObjectName(QStringLiteral("Seconds"));
        Seconds->setGeometry(QRect(160, 30, 61, 61));
        Seconds->setFrameShape(QFrame::NoFrame);
        Seconds->setLineWidth(1);
        Seconds->setSmallDecimalPoint(false);
        Seconds->setDigitCount(2);
        Seconds->setSegmentStyle(QLCDNumber::Flat);
        Seconds->setProperty("value", QVariant(0));
        Seconds->setProperty("intValue", QVariant(0));
        Milliseconds = new QLCDNumber(centralWidget);
        Milliseconds->setObjectName(QStringLiteral("Milliseconds"));
        Milliseconds->setGeometry(QRect(240, 30, 61, 61));
        Milliseconds->setFrameShape(QFrame::NoFrame);
        Milliseconds->setFrameShadow(QFrame::Sunken);
        Milliseconds->setDigitCount(2);
        Milliseconds->setSegmentStyle(QLCDNumber::Flat);
        Colone_One = new QTextEdit(centralWidget);
        Colone_One->setObjectName(QStringLiteral("Colone_One"));
        Colone_One->setEnabled(false);
        Colone_One->setGeometry(QRect(140, 30, 21, 61));
        Colone_One->setAutoFillBackground(false);
        Colone_One->setFrameShape(QFrame::NoFrame);
        Colone_One->setFrameShadow(QFrame::Sunken);
        Colone_One->setLineWidth(1);
        Colone_One->setMidLineWidth(1);
        Colone_One->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        Colone_One->setLineWrapColumnOrWidth(0);
        Colon_2 = new QTextEdit(centralWidget);
        Colon_2->setObjectName(QStringLiteral("Colon_2"));
        Colon_2->setEnabled(false);
        Colon_2->setGeometry(QRect(220, 30, 21, 61));
        Colon_2->setFrameShape(QFrame::NoFrame);
        Colon_2->setLineWidth(1);
        Stopwatch->setCentralWidget(centralWidget);

        retranslateUi(Stopwatch);

        Start_Pause_Restart->setDefault(false);


        QMetaObject::connectSlotsByName(Stopwatch);
    } // setupUi

    void retranslateUi(QMainWindow *Stopwatch)
    {
        Stopwatch->setWindowTitle(QApplication::translate("Stopwatch", "Stopwwatch", 0));
        Start_Pause_Restart->setText(QApplication::translate("Stopwatch", "Start", 0));
        Reset->setText(QApplication::translate("Stopwatch", "Reset", 0));
        Colone_One->setHtml(QApplication::translate("Stopwatch", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">:</span></p></body></html>", 0));
        Colon_2->setHtml(QApplication::translate("Stopwatch", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">:</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Stopwatch: public Ui_Stopwatch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOPWATCH_H
