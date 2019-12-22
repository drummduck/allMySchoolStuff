//Nathan Donaldson
//A3:Rule-of-Three and the Trie
//

#include "Trie.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

int main(int argc,char **argv)
{

//Check for 3 inputs
    if(argc != 3)
    {
        cout << "Program requires EXACTLY 2 text file names seperated by a space following the executable" << endl;

        return 1;
    }

//variables
    Trie trie;

    std::string line;

    const char* file_name = argv[1];

    ifstream file;

    file.open(file_name);

    //If file open, read one line at a time.
    if(file.is_open())
    {
//*************//add words to trie. addWord testing**********************
        while(getline(file,line))
        {

            trie.addword(line);

        }


    }

    //File cant open.
    else
    {
        cout << "Can't find first given textfile. Please rerun with valid text file." << endl;

        return 1;
    }

    file.close();

    file.clear();



    const char* file_name2 = argv[2];

    ifstream file2;


    //  *********** //Open second file for isWord, and allWordsWithPrefix testing.*********
    file2.open(file_name2);

    if(file2.is_open())
    {
        while(getline(file2,line))
        {
            if(trie.isWord(line))
            {
                cout << line << " is found" << endl;
            }

            else
            {
                cout << line << " is not found, did you mean: " << endl;

                vector<string> preWords = trie.allWordsWithPrefix(line);

                if(preWords.size() == 0)
                {
                    cout << " " << " " << " " <<  "no alternatives found" << endl;
                }


                else
                {
                   for(unsigned i = 0; i < preWords.size(); i++)
                    {
                        cout << " " << " " << " " << preWords[i] << endl;
                    }
                }
            }

        }
    }

        else
        {
            cout << "Can't find second given textfile. Please rerun with valid text file." << endl;

            return 1;
        }


    file2.close();
    file2.clear();


    //*********************************************************************This is for empty string prefix test, it returns everything up till about 9/10 of the way. I kept getting a segfault and i dont know why!*/
        // string testEmpty = "";

        // vector<string> preWords = trie.allWordsWithPrefix(testEmpty);

        // if(preWords.size() == 0)
        // {
        //     cout << " " << " " << " " <<  "no alternatives found" << endl;
        // }


        // else
        // {
        //     for(unsigned i = 0; i < preWords.size(); i++)
        //     {
        //         cout << " " << " " << " " << preWords[i] << endl;
        //     }
        // }



    return 0;


}
