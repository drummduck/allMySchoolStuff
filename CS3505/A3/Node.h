//Nathan Donaldson
//A3: Rule-of-Three & Trie
//This is the header file for my node.

#include <iostream>

//This carries nothing but pointers, a letter, and a boolean.
class Node
{
    //Used as a key
    char letter;

    //Words that have been added
    bool isWord;

    //Array of Node Pointers
    Node* ptrArray[26];


public:

    //Default constructor
    Node();

    //Destructor
    ~Node();

    //Returns character key
    char getLetter();

    //Sets character key
    void setLetter(char inLetter);

    //Returns if end of valid word
    bool getBool();

    //Sets valid word boolean
    void setTrue();

    //Sets false word
    void setFalse();

    //Returns pointer to node that is in the array
    Node* returnNode(int pos);

    //Creates a NEW node
    void newNode(int pos);

    //Compares input key to class key
    bool checkLetter(char checkLetter);

    //Returns true if pointer is null; false otherwise.
    bool NullPointer(int pos);

};
