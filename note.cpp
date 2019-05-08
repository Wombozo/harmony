#include "note.h"

Note::~Note()
{
}

Note::Note(char n, char a)
   {
      name = n;
      alt = (a == 'n') ? ' ' : a;
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
    std::string s;
    s+=name;
    s+=alt;
    return s; 
}



std::vector<char> arrangeBaseNotes(char base)
{
    std::vector<char> notes = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int index;
    for (int i=0; i < notes.size(); i++)
    {
        if (notes.at(i) == base)
            index = i;
    }
    std::rotate(notes.begin(),notes.begin()+index,notes.end());
    return  notes;
}

