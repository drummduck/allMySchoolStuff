//Nathan Donaldson
//A2: Classes and Facades
// The HaruPDF class creates a PDF page with certain size and font, sets the text on that page with given coordinates, and saves the file to the current executable directory with a given filename.

#include "HaruPDF.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

//Default constructor
HaruPDF::HaruPDF(){;}

//Creates a new PDF document using private member variables pdf,page, and font
void HaruPDF::createDoc()
{
    //Create a new pdf page, set the size of the page.
    pdf = HPDF_New(NULL,NULL);
    page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_LETTER, HPDF_PAGE_PORTRAIT);

    //Set the font characteristics
    font = HPDF_GetFont(pdf, "Helvetica",NULL);
    HPDF_Page_SetTextLeading(page,20);
    HPDF_Page_SetGrayStroke(page,0);
    HPDF_Page_BeginText(page);
    font = HPDF_GetFont(pdf, "Courier-Bold",NULL);
    HPDF_Page_SetFontAndSize(page,font,30);



    return;
}

//Places text on pdf page using coordinates and text given through command line
void HaruPDF::setText(unsigned i, const char* Text, float rad1, float rad2, float x, float y)
{
     //Holds the character to be put on the page
     char buf[2];

     //Coordinates of where to set the next character.
     HPDF_Page_SetTextMatrix(page, cos(rad1), sin(rad1), -sin(rad1), cos(rad1), x, y);
     buf[0] = Text[i];
     buf[1] = 0;

     //Set the character in buf at the position given above.
     HPDF_Page_ShowText (page, buf);
     angle -= 10.0;

     return;
}

//saves file in executable directory with given file name
void HaruPDF::saveFile(const char* fileName)
{

    HPDF_SaveToFile(pdf,fileName);

    HPDF_Free(pdf);

    return;
}
