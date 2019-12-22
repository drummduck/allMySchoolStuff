//Nathan Donaldson
//A2:Classes & Facades
//This is the main function that uses both HaruPDF and Spiral to create a spiral PDF

#include "Spiral.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;


int main(int argc, char **argv)
{
    //Two sets of HaruPDF's and Spiral's for the postfix and prefix increment operators
    HaruPDF haru;
    HaruPDF haru2;
    Spiral spiral(210,300,50);
    Spiral spiral2(210,300,50);

    //Text to be displayed on pdf, and unsigned integer to compare length with.
    const char* Text;
    unsigned i;

    //Attributes of both spiral's
    double textAngle, spiralAngle, x, y, textAngle2, spiralAngle2, x2, y2;

    //File names for both spiral's
    const char* fileName = "spiralPDF.pdf";
    const char* fileName2 = "spiralPDF2.pdf";


    //If there aren't exactly 2 arguments in the command, quit program and give syntax message. Otherwise use the second argument as text to place in spiral.
    if(argc != 2)
    {
        cout << "Please use the format: ./executable \"text to be used\"" << endl;

        return 0;
    }

    Text = argv[1];

    haru.createDoc();

    //This for loop displays attributes of the Spiral and calculates the position of the next character and places it on the PDF.
    for (i = 0; i < strlen (Text); i++)
    {

        cout << spiral;

        spiral++;

        textAngle = spiral.get_text_angle();
        spiralAngle = spiral.get_spiral_angle();
        x = spiral.get_text_x();
        y = spiral.get_text_y();

        haru.setText(i, Text, textAngle, spiralAngle, x, y);

    }

    haru.saveFile(fileName);


    //This section does the exact same thing but uses the prefix increment operand instead of the postfix.
    cout << "***************End of spiral++ version!***************" << endl << endl;

    haru2.createDoc();

    for (i = 0; i < strlen (Text); i++)
    {

        cout << spiral2;

        ++spiral2;

        textAngle2 = spiral2.get_text_angle();
        spiralAngle2 = spiral2.get_spiral_angle();
        x2 = spiral2.get_text_x();
        y2 = spiral2.get_text_y();

        haru2.setText(i, Text, textAngle2, spiralAngle2, x2, y2);


    }

    haru2.saveFile(fileName2);

return 0;

}
