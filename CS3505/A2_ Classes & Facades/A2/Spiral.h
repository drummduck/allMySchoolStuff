//Nathan Donaldson
//A2:Classes & Facades
//This is a header file for the class Spiral. Sets the groundwork for all functions and member variables to be used in Spiral.cpp.

#include "HaruPDF.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>

//The Spiral class takes a radius and center point, and calculates a position for HaruPDF to use to form a spiral of text.
class Spiral
{
    //Private member variables
    double centerX, centerY, radius, spiralAngle, textAngle;
    float angle = 90;

    //Public functions
public:

    //Constructor for Spiral
    Spiral(double centerX, double centerY, double radius);

    //Overloaded postfix ++ operator; calculates next position for character
    void operator++(int dummy);

    //Overloaded prefix ++ operator; calculates next position for character but a little different than above
    void operator++();

    //Returns the x position of next character placement
    double get_text_x();

    //Returns the y position of next character placement
    double get_text_y();

    //Returns angle of spiral
    double get_spiral_angle();

    //Returns angle of text
    double get_text_angle();

    //Overloads cout for Spiral; Spiral displays x and y positions, angle, and radius.
    friend std::ostream& operator<<(std::ostream& output, Spiral spiral);
};
