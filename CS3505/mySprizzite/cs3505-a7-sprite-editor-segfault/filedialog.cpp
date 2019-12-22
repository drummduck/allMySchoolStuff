//SEGFAULT
//Nathan Donaldson
//Meysam Hamel
//Scott Neville
//Aaron Mcghie
//Eric Miramontes
//Cashe Rumsey

//This is an overwritten dialog class, it is used for the starting of a new file. The dialog window takes in
//2 numbers, which count as the width and height of the canvas for the project.

#include "filedialog.h"
#include "ui_filedialog.h"
#include "model.h"
#include "QObject"
#include <iostream>
#include <QKeyEvent>


FileDialog::FileDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileDialog)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    QObject::connect(ui->CancelButton, SIGNAL(pressed()), this, SLOT(FileCancel()));
    QObject::connect(ui->OkayButton, SIGNAL(pressed()), this, SLOT(FileNew()));
}

void FileDialog::opened()
{
    ui->WidthBox->setValue(300); //default was ui->WidthBox->minimum()
    ui->HeightBox->setValue(300); //default was ui->HeightBox->minimum()
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->show();
}

FileDialog::~FileDialog()
{
    delete ui;
}

bool FileDialog::eventFilter(QObject* obj, QEvent* event)
{
    if(event->type()==QEvent::KeyPress)
        {
            QKeyEvent* key = static_cast<QKeyEvent*>(event);
            if ((key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) )
                {
                    //Enter or return was pressed
                    //Initiallize gui and model
                    emit clearFrames();
                    emit started();
                    emit newFileSettings(ui->WidthBox->value(), ui->HeightBox->value());
                    this->close();
                }
        }
    else
        {
            return QObject::eventFilter(obj, event);
        }
    return false;
}

void FileDialog::FileCancel()
{
    this->close();
}

void FileDialog::FileNew()
{
    //Initialize gui and model
    emit started();
    emit clearFrames();
    emit newFileSettings(ui->WidthBox->value(), ui->HeightBox->value());
    this->close();
}
