#include <Animal.cpp>
#include <vector>
using namespace std:


int main()
{

    Cat sparkles;
    Dog Kupo;
    Animal animal;

    std::vector<Animal*> vec;

    vec.push_back(&sparkles);
    vec.push_back(&Kupo);
    vec.push_back(&animal);

    for(auto Animal : vec)
    {

        Animal->speak();

    }

    return 0;
}
