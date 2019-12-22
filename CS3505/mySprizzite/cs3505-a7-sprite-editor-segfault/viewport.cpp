//SEGFAULT
//Nathan Donaldson
//Meysam Hamel
//Scott Neville
//Aaron Mcghie
//Eric Miramontes
//Cashe Rumsey

#include "viewport.h"

//constructor
viewport::viewport(int x,int y, int width, int height)
{
    Mx = x;
    My = y;
    Mheight = height;
    Mwidth = width;
}

int viewport::getLeft() {
    return Mx;
}

int viewport::getRight() {
    return Mx + Mwidth;
}

int viewport::getTop() {
    return My;
}

int viewport::getBot() {
    return My + Mheight;
}

int viewport::getHeight() {
    return Mheight;
}

int viewport::getWidth() {
    return Mwidth;
}

void viewport::setHeight(int height) {
    Mheight = height;
}

void viewport::setWidth(int width) {
    Mwidth = width;
}

void viewport::moveHoriz(int dist){
    Mx += dist;
}

void viewport::moveVert(int dist) {
    My += dist;
}

void viewport::moveXTo(int newX) {
    Mx = newX;
}

void viewport::moveYTo(int newY) {
    My = newY;
}
