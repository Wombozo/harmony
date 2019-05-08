#include "note.h"

Note::~Note()
{
}

Note::Note(char n, char a)
   {
       name = n;
       alt = a;
   }

char Note::getName()
    {
        return name;
    }

char Note::getAlt()
     {
         return alt;
     }

std::string Note::display()
{
//    std::cout << "Note " << name << alt << std::endl;
    std::string s;
    s+=name;
    s+=alt;
    return s; 
}
