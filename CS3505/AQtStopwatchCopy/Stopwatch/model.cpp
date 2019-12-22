#include "model.h"
#include <cstdlib>



Model::Model(QObject *parent) : QObject(parent)
{

    Start_Pause_Restart_Text = "Start";
    Min = 0;
    Sec = 0;
    Ms = 0;
    Pause = false;
    tempTime = 0;

    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
}




void Model::Start_Pause_Restart()
{

    if(Start_Pause_Restart_Text == "Start")
    {
       Start_Pause_Restart_Text = "Pause";
       Pause = false;
       Time.start();
       Timer->start(1);
       emit Start_Pause_Restart_Data(Start_Pause_Restart_Text);
    }

    else if(Start_Pause_Restart_Text == "Pause")
    {
       Start_Pause_Restart_Text = "Restart";
       Pause = true;
       tempTime += Time.elapsed();
       emit Start_Pause_Restart_Data(Start_Pause_Restart_Text);

    }

    else if(Start_Pause_Restart_Text == "Restart")
    {
       Start_Pause_Restart_Text = "Pause";
       Time.start();
       emit Start_Pause_Restart_Data(Start_Pause_Restart_Text);
       Pause = false;
    }
}

void Model::UpdateTime()
{


        if(Pause == false)
        {
            Min = ((tempTime + Time.elapsed())/60000) % 60;
            Sec = ((tempTime + Time.elapsed())/1000) % 60;
            Ms = ((tempTime + Time.elapsed())/10) % 100;

            std::string Min_Str = std::to_string(Min);
            std::string Sec_Str = std::to_string(Sec);
            std::string Ms_Str = std::to_string(Ms);



            if(Min < 10)
            {
                Min_Str.insert(0,1,'0');
            }

            if(Sec < 10)
            {
                Sec_Str.insert(0,1,'0');
            }

            if(Ms < 10)
            {
                Ms_Str.insert(0,1,'0');
            }


            const QString Min_QStr = QString::fromStdString(Min_Str);
            const QString Sec_QStr = QString::fromStdString(Sec_Str);
            const QString Ms_QStr = QString::fromStdString(Ms_Str);

            emit Min_Data(Min_QStr);
            emit Sec_Data(Sec_QStr);
            emit Ms_Data(Ms_QStr);

        }
}

void Model::Reset()
{
    Pause = true;
    Min = 0;
    Sec = 0;
    Ms = 0;
    tempTime = 0;
    Start_Pause_Restart_Text = "Start";

    emit Reset_Data(Start_Pause_Restart_Text);
    emit Min_Data("00");
    emit Sec_Data("00");
    emit Ms_Data("00");
}




