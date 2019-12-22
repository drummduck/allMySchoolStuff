//Nathan Donaldson
//A2:Classes & Facades
//The Spiral class takes a radius and center point, and calculates a position for HaruPDF to use to form a spiral of text.

#include "Spiral.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//Constructor for Spiral
Spiral::Spiral(double centerX, double centerY, double radius) : centerX(centerX), centerY(centerY), radius(radius) {}

//Overloaded postfix ++ operator; calculates next position for character
void Spiral::operator++(int dummy)
{

    float spiralAngle;

    textAngle = ((angle - 90) / 180 * M_PI);
    spiralAngle = (angle / 180 * M_PI);

    //x & y coordinates of character.
    centerX = 306 + cos(spiralAngle) * radius;
    centerY = 396 + sin(spiralAngle) * radius;

    //Adjustments for biggest effect on spiral.
    angle -= 12;
    radius += 1.5;


}

//Overloaded prefix ++ operator; calculates next position for character but a little different than above
void Spiral::operator++()
{
    float spiralAngle;

    textAngle = ((angle - 90) / 180 * M_PI);
    spiralAngle = (angle / 180 * M_PI);

    //x & y coordinates of character.
    centerX = 306 + cos(spiralAngle) * radius;
    centerY = 396 + sin(spiralAngle) * radius;

    //Adjustments for biggest effect on spiral.
    angle -= 12;
    radius += 1.5;

    }

//Returns the x position of next character placement
double Spiral::get_text_x()
{
    return centerX;
}

//Returns the y position of next character placement
double Spiral::get_text_y()
{
    return centerY;
}

//Returns angle of spiral
double Spiral::get_spiral_angle()
{
    return radius;
}

//Returns angle of text
double Spiral::get_text_angle()
{
  return textAngle;
}

//Overloads cout for Spiral; Spiral displays x and y positions, angle, and radius.
ostream& operator<<(ostream& output, Spiral spiral)
{

    //These while loops keep the information in the 360 degree range for the user. The HPDF_Page_SetTextMatrix function inside the Haru library takes care of this when placing text.
    while(spiral.angle > 360)
    {
        spiral.angle -= 360;
    }

    while(spiral.angle < -360)
    {
        spiral.angle += 360;
    }

    output << "The x position for the character is: " << spiral.get_text_x() << endl;
    output << "The y position for the character is is: " << spiral.get_text_y() << endl;
    output << "The angle is: " << spiral.angle << endl;
    output << "the radius is: " << spiral.radius << endl << endl;

    return output;
}
