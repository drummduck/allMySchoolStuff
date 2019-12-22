//SEGFAULT
//Nathan Donaldson
//Meysam Hamel
//Scott Neville
//Aaron Mcghie
//Eric Miramontes
//Cashe Rumsey

#include "sprite.h"
#include <QImage>
#include <iostream>
#include <QDebug>

Sprite::Sprite(int width, int height)
{
    Mwidth = width;
    Mheight = height;
    //initialize all pixels
    for (int i = 0; i < Mwidth*Mheight; i++) {
        Mpixels.push_back(Qt::white);
    }
}

void Sprite::changePixelColor(int x, int y, QColor color) {
    Mpixels[y*Mwidth+x] = color;
}

QColor Sprite::getPixelColor(int x, int y) {
    int index = y*Mwidth + x;
    return Mpixels[index];
}

int Sprite::getWidth() {
    return Mwidth;
}

int Sprite::getHeight() {
    return Mheight;
}

//resets all pixels of sprite
void Sprite::resetPixels()
{
    //initialize all pixels
    for (int i = 0; i < Mpixels.size(); i++)
    {
        Mpixels[i] = Qt::white;
    }
}

std::vector<QColor> Sprite::getPixels()
{
    return Mpixels;
}

//takes an image and pastes it into the map
void Sprite::pasteQMapAt(int x,int y,QImage map) {
    //TODO: check that x,y are suitable
    for (int i = x; i < x + map.width(); i++) {
        for (int j = y; j < y + map.height(); j++) {
            this->changePixelColor(i,j, map.pixel(i-x,j-y));
            //std::cout<<map.pixel(i-x, j-y) << std::endl;
        }
    }
}
