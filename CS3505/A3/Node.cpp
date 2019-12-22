 //Nathan Donaldson
//A3: Rule-of-Three & Trie
//.cpp file for Node
#include "Node.h"
#include <cstddef>


using namespace std;

//Default constructor, initializes array to nullptr's and sets word validity to false.
Node::Node()
{
    for(int i = 0; i < 26; i++)
       {
          ptrArray[i] = nullptr;
       }

    letter = '!';
    isWord = false;

}

//Destructor, This holds everything so there is no need for one in Trie class.
Node::~Node()
{
    for(int i = 0; i < 26; i++)
        {

            if(ptrArray[i] != nullptr)
               {
                  delete ptrArray[i]->returnNode(i);
                  ptrArray[i] = nullptr;
               }
        }
}

//Returns key char
char Node::getLetter()
    {
        return letter;
    }

//Compares input key to class key
bool Node::checkLetter(char checkLetter)
{
    if(checkLetter == letter)
       {
          return true;
       }

    return false;
}

//Sets character key
void Node::setLetter(char inLetter)
{
    letter = inLetter;
}

//Returns if end of valid word
bool Node::getBool()
{
    return isWord;
}

//Sets valid word boolean
void Node::setTrue()
{
    isWord = true;
}

//Sets false to word validity
void Node::setFalse()
{
    isWord = false;
}

//Creates a new node and has the pos in the node array point to it
void Node::newNode(int pos)
{
    ptrArray[pos] = new Node();
}

//Returns node that array pos is pointing to
Node* Node::returnNode(int pos)
{
  return ptrArray[pos];
}

//Returns whether array pointer is null or not.
bool Node::NullPointer(int pos)
{
    if(ptrArray[pos] == nullptr)
       {
         return true;
       }

    return false;
}
