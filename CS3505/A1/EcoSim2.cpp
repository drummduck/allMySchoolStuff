#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <istream>


using namespace std;



int main()
{

  int numRabbits;
  int numFoxes;
  int steps;
  int* stepsPointer;
  string numRabbitsStr;
  string numFoxesStr;
  string input;
  bool secondNum;
  bool spaceCheck;
  bool commaCheck;

  cout << "What is the initial fox and rabbit population?" << endl;


  getline(cin, input);

  secondNum = false;

  for(int i = 0; i <= input.length();i++)
  {
      if(input[i] == ' ')
      {
          spaceCheck = true;
      }

      else if(input[i] == ',')
      {
          commaCheck = true;
      }
  }

  if(spaceCheck != true && commaCheck != true)
  {
      cout << "Please enter populations in this format: #, #" << endl;
      return 0;
  }

  for(int i = 0; i <= input.length(); i++)
    {

      if(numRabbitsStr.length() == 0 && secondNum == false)
        {
          numRabbitsStr = input[i];
        }

     else if(input[i] == ',' && secondNum == false)
        {
          for(int j = 0; j < numRabbitsStr.length(); j++)
            {
              if(!isdigit(numRabbitsStr[j]))
                {
                  cout << "Please enter populations in this format: #, #" << endl;
                  return 0;
                }
            }

          if(input[i+1] != ' ')
            {
              cout << "Please enter populations in this format: #, #" << endl;
              return 0;
            }
        }

      else if(input[i] == ' ' && secondNum == false)
        {
            if(input[i-1] != ',')
              {
                  cout << "Please enter populations in this format: #, #" << endl;
                  return 0;
              }

                secondNum = true;
        }


     else if(numRabbitsStr.length() > 0 && secondNum == false)
        {
          numRabbitsStr += input[i];
        }

     else if(secondNum == true && numFoxesStr.length == 0)
        {
            if(input[i-1] != ' ')
            {
                cout << "Please enter population in this format: #, #" << endl;
            }
          numFoxesStr = input[i];
        }

     else if(secondNum == true && numFoxesStr.length > 0)
     {
         numFoxesStr = input[i];
     }

    }

  numRabbits = stoi(numRabbitsStr);
  numFoxes = stoi(numFoxesStr);
  steps = 0;
  stepsPointer = &steps;

        while(numRabbits >= 1 || numFoxes >= 1 || steps <= 500)
          {
        cout << "you have reached the update while loop, the numRabbits is " << numRabbits << " and numFoxes is " << numFoxes << endl;
            break;

          }


        return 0;



}


void updatePopulations(double g, double K, double p, double m, double c, double &numRabbits, double &numFoxes)
{

}
