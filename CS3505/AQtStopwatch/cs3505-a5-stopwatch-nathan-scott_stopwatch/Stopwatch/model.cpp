//Nathan Donaldson & Scott Neville
//A5: A Qt Stopwatch

//This is the cpp file for the Model, the Model is what keeps track of all data
//that is goint to be updated on the UI through the view. It keeps track of Minutes, Seconds,
//and Milliseconds that are used in a timer in the UI. It also keeps track of the Text displayed
//on a button and three QLCDNumber displays.
#include "model.h"
#include <cstdlib>


//Sets the member variables to the default values and creates a QTimer, as well
//as a connection between the timeout signal from Timer and the UpdateTime method inside this class.
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



//This method keeps track of the text on the buttons and numbers in the UI.
//This method is invoked when the Start/Pause/Restart button is pushed.
void Model::Start_Pause_Restart()
{
    //If Start/Pause/Restart is pushd and the text on it is "Start", we change
    //the button's text to "Pause" via signal fire to view to update UI and Start the
    //Timer(which fires off timeout signal every 1 millisecond)and the Time(which keeps track of time elapsed).
    if(Start_Pause_Restart_Text == "Start")
    {
       Start_Pause_Restart_Text = "Pause";
       Pause = false;
       Time.start();
       Timer->start(1);
       emit Start_Pause_Restart_Data(Start_Pause_Restart_Text);
    }

    //If Start/Pause/Restart button is pushed and the text on it is "Pause", We change
    //the text of the button to "Restart" via signal fire to view to update UI and set a boolean
    //Pause(keeps track of when to update time member variables or not) to true.
    //Also keep track of time that elapsed since pause push so we can keep appropriate
    //time when "Restart" is pressed.
    else if(Start_Pause_Restart_Text == "Pause")
    {
       Start_Pause_Restart_Text = "Restart";
       Pause = true;
       tempTime += Time.elapsed();
       emit Start_Pause_Restart_Data(Start_Pause_Restart_Text);

    }

    //If Start/Pause/Restart button is pushed and the text on it is "Restart", we
    //change the text of the button to "Pause" via signal fire to view to update UI.
    //Restart Time and set Pause to false so we can update time variables again.
    else if(Start_Pause_Restart_Text == "Restart")
    {
       Start_Pause_Restart_Text = "Pause";
       Time.start();
       emit Start_Pause_Restart_Data(Start_Pause_Restart_Text);
       Pause = false;
    }
}

//This method is invoked via the Time's timeout signal. It updates member variable times
//and signals the view to update these values. This method is invoked every 1 millisecond.
void Model::UpdateTime()
{

        //If Pause is false, update the time. If number is only one digit, lead
        //display with a zero. To do this we must cast the Min/Sec/Ms to a std::string
        //and if there is only one digit, we insert a leading zero to the string. The
        //std::string is converted to a QString(QLCDNumber calls for a QString) and
        //the display is changed in the UI via a signal fire to the view.
        if(Pause == false)
        {
            Min = ((tempTime + Time.elapsed())/60000) % 60;
            Sec = ((tempTime + Time.elapsed())/1000) % 60;
            Ms = ((tempTime + Time.elapsed())/10) % 100;

            //Change int to string
            std::string Min_Str = std::to_string(Min);
            std::string Sec_Str = std::to_string(Sec);
            std::string Ms_Str = std::to_string(Ms);


            //Add leading zero if needed
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

            //Change std::string to Qstring
            const QString Min_QStr = QString::fromStdString(Min_Str);
            const QString Sec_QStr = QString::fromStdString(Sec_Str);
            const QString Ms_QStr = QString::fromStdString(Ms_Str);

            //Fire signal
            emit Min_Data(Min_QStr);
            emit Sec_Data(Sec_QStr);
            emit Ms_Data(Ms_QStr);

        }
}

//This method is invoked when the "Reset" button is pushed.
//This method resets all data member variables to their default state(most of them)
//and fires the signals to the view to update the UI to its default state.
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




