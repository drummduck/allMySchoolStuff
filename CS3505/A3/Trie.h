//Nathan Donaldson
//A3:Rule-of-Three and the Trie
//Header file for Trie class

#include "Node.h"
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstddef>
#include <math.h>

//Uses all of the below functions to manipulate nodes and their pointers.
class Trie
{
    //root node
    Node root;
    std::string word;

public:

    //Adds a tree to the trie.
    void addword(std::string inWord);

    //Tells wether input word is valid or not
    bool isWord(std::string inWord);

    //Returns all words that start with a given prefix, returns all for empty string. ***I was having problems getting a segfault on this for some reason*** It would do just fine till a certain way down. For the dictionary it would work till the y's****
    std::vector<std::string> allWordsWithPrefix(std::string preWord);

    //Destructor **nothing needed to be done, it is all done in the Node class**
    ~Trie();

    //Default constructor
    Trie();

    //Copy constructor **Needed to do this in Node class as well**
    Trie(const Trie& other);

    //Equals Overload **Needed to do this in Node class as well**
    Trie& operator=(const Trie& other);

    //Calculates position of index for wanted word.
    int getIndex(char letter);

    //Recursive helper method for allWordsWithPrefix
    std::vector<std::string> PreRecurse(Node* node, std::vector<std::string> words, std::string letters);
};
