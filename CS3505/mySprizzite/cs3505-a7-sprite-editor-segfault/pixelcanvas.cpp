//SEGFAULT
//Nathan Donaldson
//Meysam Hamel
//Scott Neville
//Aaron Mcghie
//Eric Miramontes
//Cashe Rumsey

#include "pixelcanvas.h"

PixelCanvas::PixelCanvas(int width, int height, int pixelViewSize)
{
    MpixelViewSize = pixelViewSize;
    map = new QPixmap(width, height);
    map->fill(BACKGROUND_COLOR);
    painter = new QPainter(map);
    Mgrid = true;
}

PixelCanvas::~PixelCanvas() {
    painter->end();
    delete map;
}

QPixmap* PixelCanvas::getMap(){
    return map;
}

void PixelCanvas::drawPixel(int x, int y, QColor color) {

    //draw rect of color on map
    QRect rect(x, y, MpixelViewSize, MpixelViewSize);
    painter->setBrush(QBrush(color));

    if(Mgrid)painter->drawRect(rect);
    else painter->fillRect(rect, painter->brush());
}

void PixelCanvas::resize(int new_width, int new_height){
    QPixmap* newMap = new QPixmap(new_width, new_height);
    newMap->fill(BACKGROUND_COLOR);

    //set new painter
    delete painter;
    painter = new QPainter(newMap);

    painter->drawPixmap(0, 0, *map);
    delete map;
    map = newMap;
}

int PixelCanvas::getPixelViewSize() {
    return MpixelViewSize;
}

void PixelCanvas::setPixelViewSize(int newSize) {
    MpixelViewSize = newSize;
}

void PixelCanvas::moveHoriz(int val) {
    QPixmap* newMap = new QPixmap(map->width(), map->height());
    newMap->fill(BACKGROUND_COLOR);

    delete painter;
    painter = new QPainter(newMap);

    painter->drawPixmap(val*MpixelViewSize, 0, *map);
    delete map;
    map = newMap;
}

void PixelCanvas::moveVert(int val) {
    QPixmap* newMap = new QPixmap(map->width(), map->height());
    newMap->fill(BACKGROUND_COLOR);

    delete painter;
    painter = new QPainter(newMap);

    painter->drawPixmap(0, val*MpixelViewSize, *map);
    delete map;
    map = newMap;
}

void PixelCanvas::paintColumn(int xVal, std::vector<QColor> pixels) {
    for(int i = 0; i < pixels.size(); i++) {
        painter->setBrush(pixels[i]);
        QRect rect(xVal*MpixelViewSize, i*MpixelViewSize, MpixelViewSize, MpixelViewSize);
        painter->setBrush(QBrush(pixels[i]));
        if(Mgrid)painter->drawRect(rect);
        else painter->fillRect(rect, painter->brush());
    }
}

void PixelCanvas::paintRow(int yVal, std::vector<QColor> pixels) {
    for(int i = 0; i < pixels.size(); i++) {
        //painter->setBrush(pixels[i]);
        QRect rect(i*MpixelViewSize, yVal*MpixelViewSize, MpixelViewSize, MpixelViewSize);
        painter->setBrush(QBrush(pixels[i]));
        if(Mgrid)painter->drawRect(rect);
        else painter->fillRect(rect, painter->brush());
    }
}

void PixelCanvas::drawSelectRect(int left, int top, int right, int bot) {
    //change pen to select pen
    QPen pen(SELECTION_BORDER_COLOR);
    pen.setStyle(Qt::DashLine);
    painter->setPen(pen);

    //draw lines of rect
    painter->drawLine(left, top, right, top);
    painter->drawLine(right, top, right, bot);
    painter->drawLine(right, bot, left, bot);
    painter->drawLine(left, bot, left, top);

    //change pen back to normal pen
    pen.setColor(PIXEL_BORDER_COLOR);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
}

void PixelCanvas::toggleGrid(bool on) {
    Mgrid = on;
}

void PixelCanvas::clear() {
    map->fill(BACKGROUND_COLOR);
}
