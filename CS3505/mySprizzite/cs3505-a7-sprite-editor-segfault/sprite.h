//SEGFAULT
//Nathan Donaldson
//Meysam Hamel
//Scott Neville
//Aaron Mcghie
//Eric Miramontes
//Cashe Rumsey

//Header file for sprite class; member variables and methods declared here

#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include <QColor>
#include <QImage>

class Sprite
{
    int Mwidth;
    int Mheight;
    std::vector<QColor> Mpixels;

public:
    //Constructor taking in (width, height)
    Sprite(int, int);

    //Consider another constructor that takes in a bmp file

    //Change the color of one pixel
    void changePixelColor(int, int, QColor);

    //get the color of a pixel
    QColor getPixelColor(int, int);

    //returns width
    int getWidth();

    //returns height
    int getHeight();

    void resetPixels();

    void pasteQMapAt(int,int,QImage);

    std::vector<QColor> getPixels();
};

#endif // SPRITE_H
