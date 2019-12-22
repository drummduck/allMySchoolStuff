//Nathan Donaldson
//A3:Rule-of-Three and the Trie
//.cpp file for Trie

#include "Trie.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstddef>
#include <iostream>

using namespace std;


//Default constructor
Trie::Trie(){;}


//Did not have to do anything for this because all data was held in Nodes. Never created a NEW node in this class. Node has its own destructor and runs at end.
Trie::~Trie()
{


}

//Copy constructor **Needed to do this in Node class as well**
Trie::Trie(const Trie& other)
{


}

//Takes a string and adds it to the Trie using nodes and pointers
void Trie::addword(std::string newWord)
{

    Node* node;

    if(newWord == "")
       {
          return;
       }

    //Checks for Null pointer, if null, creates a new Node and points to it. Uses key char to find which position.
    else if(root.NullPointer(getIndex(newWord[0])))
            {
               root.newNode(getIndex(newWord[0]));
               node = root.returnNode(getIndex(newWord[0]));
               node->setLetter(newWord[0]);
            }

    //If not null, checks position with key char and follows the pointer.
    else if(root.returnNode(getIndex(newWord[0]))->checkLetter(newWord[0]))
       {
          node = root.returnNode(getIndex(newWord[0]));
       }

    // For testing purposes
    else
       {
          cout << "unknown error" << endl;
          return;
       }


    //Adding the word, code above set up pointers from root to first branch
    for(unsigned i = 0; i < newWord.size(); i++)
       {

            //End of word, set to valid word
            if(i == newWord.size() - 1)
                {
                    node->setTrue();
                    return;
                }


            //Check for Nullpointer, if null, create new node and point to it.
            if(node->NullPointer(getIndex(newWord[i+1])))
                {
                    node->newNode(getIndex(newWord[i+1]));
                    node = node->returnNode(getIndex(newWord[i+1]));
                    node->setLetter(newWord[i+1]);
                }


            //Check key char and follow pointer to node.
             else if(node->returnNode(getIndex(newWord[i+1]))->checkLetter(newWord[i+1]))
                {
                    node = node->returnNode(getIndex(newWord[i+1]));
                }

            //Testing purposes
             else
                {
                    cout << "unknown error occured" << endl;
                    return;
                }

      }

    return;
    
}

//Returns whether or not the word is valid
bool Trie::isWord(std::string checkWord)
{

    Node* node;

    //Not a word
    if(checkWord == "")
       {
          return false;
       }

    //Checing char key and if null pointer at that key
    else if(root.NullPointer(getIndex(checkWord[0])))
       {
          return false;
       }

    //If not null, check key and follow pointer
    else if(root.returnNode(getIndex(checkWord[0]))->checkLetter(checkWord[0]))
       {
          node = root.returnNode(getIndex(checkWord[0]));
       }

    //Testing purposes
    else
       {
          cout << "unknown error" << endl;
          return false;
       }

    //String to check if we find the right word
    std::string word = "";

    //Return true if valid boolean and word matches input word
    for(unsigned i = 0; i < checkWord.size(); i++)
       {
          word += node->getLetter();

          if(word == checkWord && node->getBool())
            {
              return true;
            }

          else if(node->NullPointer(getIndex(checkWord[i+1])))
            {
              return false;
            }

          //Follow pointers otherwise
          else if(node->returnNode(getIndex(checkWord[i+1]))->checkLetter(checkWord[i+1]))
            {
              node = node->returnNode(getIndex(checkWord[i+1]));
            }

          //Default return
          else
            {
              return false;
            }

    }

    return false;

}


//Takes all words with given prefix and returns them in a string vector
std::vector<std::string> Trie::allWordsWithPrefix(std::string preWord)
{
    //String to compare and follow to before finding all words
    string preCheck = "";

    std::vector<std::string> preWords;
    Node* node;

    //This area returns all of the strings in the dictionary **for some reason i kept getting a segfault around about 9/10 of it finishing. I couldnt figure out why**
    if(preWord == "")
       {

           //Check for Null pointer, if not, set node.
           for(int i = 0; i < 26; i++)
              {
                 if(root.NullPointer(getIndex(preWord[i])))
                   {
                      continue;
                   }

                 else
                   {
                      node = root.returnNode(i);

                      //add char to preCheck and push any valid words into vector.
                      preCheck = node->getLetter();
                      if(node->getBool())
                        {
                          preWords.push_back(preCheck);
                        }
                   }

                 //Recursive function call
                  preWords = PreRecurse(node, preWords, preCheck);
           }

           return preWords;
       }


    //Set up root node again if not empty string input.
    else if(root.NullPointer(getIndex(preWord[0])))
       {
          return preWords;
       }

    else if(root.returnNode(getIndex(preWord[0]))->checkLetter(preWord[0]))
       {
          node = root.returnNode(getIndex(preWord[0]));
       }

    //For testing purposes
    else
       {
          cout << "unknown error" << endl;

          return preWords;
       }

    //Follow the branches and pull everything out with that prefix
    for(unsigned i = 0; i < preWord.size(); i++)
       {

         preCheck += node->getLetter();

         //if the check has been reached, go into recursive function.
         if(preCheck == preWord)
            {
                if(node->getBool())
                   {
                     preWords.push_back(preCheck);
                   }

                preWords = PreRecurse(node, preWords, preCheck);

                return preWords;

            }

         //Continue following pointers till preCheck is reached.
         if(node->NullPointer(getIndex(preWord[i+1])))
            {
                continue;
            }

         else if(node->returnNode(getIndex(preWord[i+1]))->checkLetter(preWord[i+1]))
            {
               node = node->returnNode(getIndex(preWord[i+1]));
            }

         //For testing purposes
          else
            {
               cout << "unknown error occured" << endl;
               return preWords;
            }

    }
      return preWords;

}


//Equals overload, could not be implemented in Trie, had to be implemented in Node
Trie& Trie::operator=(const Trie& other)
{


}

//Returns index value of array
int Trie::getIndex(char letter)
{
    int i = ((int)letter)-((int)'a');

    return i;
}

//Recursive method that adds every word with prefix to vector of strings.
vector<string> Trie::PreRecurse(Node* node, vector<string> words, string letters)
{
    vector<string> preWords = words;
    string preCheck = letters;
    Node* newNode;


    //If null, go till finding one that is not.
    for(int i = 0; i < 26; i++)
       {

          if(node->NullPointer(i))
             {
                 continue;
             }

          //check boolean, if valid word, put in vector.
          else
             {
               newNode = node->returnNode(i);

               preCheck += newNode->getLetter();

               if(newNode->getBool())
                  {
                       preWords.push_back(preCheck);
                  }

               preWords =  PreRecurse(newNode, preWords, preCheck);

               preCheck = letters;
             }
       }

    return preWords;

}
