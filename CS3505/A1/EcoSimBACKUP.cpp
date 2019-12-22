//Nathan Donaldson
//A1: C++ Starter
//This program asks the user for 2 numbers to be used to simulate the population of a fox/rabbit ecosystem.



#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <istream>
#include <cstdlib>
#include <cmath>

using namespace std;

//Takes input from main and updates (by reference) the populations in main using formula's
//Also calls charting to start the output process.
void updatePopulations(double g, double K, double p, double m, double c, double &numRabbits, double &numFoxes);

//Takes in values from updatePopulations and figures out order of cout and the spacing then calls plotCharacter for each character.
void charting(double numRabbits, double numFoxes, double scale);

//Takes in stepsPointer (pointer that points to steps int in main) and changes the value of what that pointer points to.
void incrementCounter(int* pointer);

//Takes in population amount from charting and the character that represents foxes/rabbits/both and prints spaces and the characters.
void plotCharacter(int number, char character);


//The main function asks the user for input. Then, with that input, it makes sure that the format is: #, #.
//If the format is correct, the program then calls the updatePopulation function to simulate the population changes over a set number of iterations.
//It also calls incrementCounter, which takes a pointer that points at the steps int and increments it until set number is reached.
int main()
{
  //Rabbit population
  double numRabbits;

  //Fox population
  double numFoxes;

  //Amount of times to update population.
  int steps;

  //Integer pointer that points at steps integer.
  int* stepsPointer;

  //Rabbit population string from cin.
  string numRabbitsStr;

  //Fox population string from cin.
  string numFoxesStr;

  //The line of the input.
  string input;

  //Check if there is space between comma and second number
  bool spaceCheck;

  //Check if there is comma between first number and space
  bool commaCheck;

  //True once first number is read.
  bool secondNum;

  //set values for updatePopulation formula
  double rabbitGrowth, predationRate, foxPreyConversion, foxMortalityRate, carryCapacity;



  cout << "What is the initial fox and rabbit population?" << endl;

  //store user input in a seperate string for format checking.
  getline(cin, input);

  //check for space and comma inside of user input. If one is not in it, end the program and give a format requirement message.
  spaceCheck = false;
  commaCheck = false;

  for(int i = 0; i <= input.length(); i++)
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

  if(commaCheck != true && spaceCheck != true)
    {
      cout << "Please enter populations in this format: #, #" << endl;
      return 0;
    }

  secondNum = false;

  //Checking for correct format of input.
  for(int i = 0; i <= input.length(); i++)
    {

      //The beginning of the first number, store in seperate string.
      if(numRabbitsStr.length() == 0 && secondNum == false)
        {
          numRabbitsStr = input[i];
        }

      //If comma is reached, check seperate rabbit string to see if digit. If not quit program and give format requirement message.
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

        //If there is no space after the comma, quit the program and give format requirement message.
      if(input[i+1] != ' ')
          {
            cout << "Please enter populations in this format: #, #" << endl;
            return 0;
          }
       }

      //If space is reached, check to see if comma was before. If not quit program and give format requirement message, otherwise we are now at the second number.
     else if(input[i] == ' ' && secondNum == false)
        {
          if(input[i-1] != ',')
            {
              cout << "Please enter populations in this format: #, #" << endl;
              return 0;
            }
          secondNum = true;
        }

      //We have not reached comma yet, keep adding to first number string.
     else if(numRabbitsStr.length() > 0 && secondNum == false)
        {
          numRabbitsStr += input[i];
        }

      //We are not at the beginning of the second number. If space is not before, quit program and give format requirement message.
     else if(secondNum == true && numFoxesStr.length() == 0)
        {
          if(input[i-1] != ' ')
          {
            cout << "Please enter populations in this format: #, #" << endl;
            return 0;
          }
          numFoxesStr = input[i];
        }

      //Havent reached end of second number, keep adding to second number string.
     else if(secondNum == true && numFoxesStr.length() > 0)
       {
         numFoxesStr += input[i];
       }

      //Something wrong happened, quit program and give format requirement message.
     else
       {
         cout << "Please enter populations in this format: #, #" << endl;
         return 0;
       }
    }

  //Check second number string to see if it can be an integer. If not quit program and give format requirement message.
  for(int i = 0; i < numFoxesStr.length()-1; i++)
    {

      if(!isdigit(numFoxesStr[i]))
        {
          cout << "Please enter populations in this format: #, #" << endl;
          return 0;
        }
    }

  //put number strings into the integers.
  stringstream stream(numRabbitsStr);

  stream >> numRabbits;

  stringstream stream2(numFoxesStr);

  stream2 >> numFoxes;

  //number of steps and pointer to number of steps for incrementCounter function.
  steps = 0;
  stepsPointer = &steps;

  //preset values for updatePopulations function.
  rabbitGrowth = 0.2;
  predationRate = 0.002;
  foxPreyConversion = 0.6;
  foxMortalityRate = 0.2;
  carryCapacity = 1000.0;

  //Continue updating the populations and incrementing counter until counter limit is reached.
  while(numRabbits >= 1 && numFoxes >= 1 && steps <= 500)
    {

      updatePopulations(rabbitGrowth, carryCapacity, predationRate, foxMortalityRate, foxPreyConversion, numRabbits, numFoxes);
      incrementCounter(stepsPointer);

    }


        return 0;

}

//Takes input from main and updates (by reference) the populations in main using formula's
//Also calls charting to start the output process.
void updatePopulations(double g, double K, double p, double m, double c, double &numRabbits, double &numFoxes)
{
  //Use formulas and preset scale to update referenced populations.
  numRabbits += ((g*numRabbits)*(1-(numRabbits/K)))-(p*numRabbits*numFoxes);
  numFoxes +=  (c*p*numRabbits*numFoxes)-(m*numFoxes);
  double scale = 0.1;

  //Setup formatting for plotting.
  charting(numRabbits, numFoxes,  scale);
}

//Takes in values from updatePopulations and figures out order of cout and the spacing then calls plotCharacter for each character.
void charting(double numRabbits, double numFoxes, double scale)
{
  //symbols for plotting.
  char Fox = 'F';
  char Rabbit = 'r';
  char both = '*';

  //scale populations for plotting.
  double scaledRabbits = floor(numRabbits * scale);
  double scaledFoxes = floor(numFoxes * scale);

  //Check to see which symbols are plotted first and at what locations.
  if(scaledRabbits != scaledFoxes)
    {
      if(scaledRabbits > scaledFoxes)
    {
      plotCharacter(scaledFoxes, Fox);
      plotCharacter((scaledRabbits - scaledFoxes), Rabbit);
    }

      else if(scaledFoxes > scaledRabbits)
    {
      plotCharacter(scaledRabbits, Rabbit);
      plotCharacter((scaledFoxes - scaledRabbits), Fox);
    }

      cout << endl;
    }

  else
    {
      plotCharacter(scaledRabbits, both);
      cout << endl;
    }

}

//Takes in stepsPointer (pointer that points to steps int in main) and changes the value of what that pointer points to.
void incrementCounter(int* pointer)
{
  //take pointer to steps integer and dereference it and add 1 to it.
  *pointer = *pointer + 1;

}

//Takes in population amount from charting and the character that represents foxes/rabbits/both and prints spaces and the characters.
void plotCharacter(int number, char character)
{

  //print symbol
  for(int i = 0; i <= number - 1; i++)
    {
      cout << ' ';
    }

  cout << character;
}
