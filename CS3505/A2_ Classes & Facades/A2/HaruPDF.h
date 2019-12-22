//Nathan Donaldson
//A2: Classes & Facades
//This is the header file for HaruPDF class, it sets the ground work for all the member variables and functions.

#include "../libharu/include/hpdf.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>

// The HaruPDF class creates a PDF page with certain size and font, sets the text on that page with given coordinates, and saves the file to the current executable directory with a given filename.
class HaruPDF
{

//Private member variables
float angle, rad1, x, y;
HPDF_Doc pdf;
HPDF_Page page;
HPDF_Font font;

//Public functions
public:

//Default constructor
  HaruPDF();

//Creates a new PDF document using private member variables pdf,page, and font
  void createDoc();

//Places text on pdf page using coordinates and text given through command line
  void setText(unsigned i, const char* Text, float rad1, float rad2, float x, float y);

//saves file in executable directory with given file name
  void saveFile(const char* fileName);

};





