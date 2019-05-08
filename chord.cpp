#include "chord.h"

Chord::Chord(char root, char alt, std::string n) : Note(root,alt)
{
    notes.clear();
    notes.insert(notes.begin(),*this);
    setNameChord();
}

Chord::~Chord()
{
}

const std::string Chord::valid_chords()
{
    return "M, m, aug, dim, 7, m7, M7, 7b5, dim7";
}

void Chord::setNameChord()
{
    nameChord.clear();
    nameChord = this->name + this->alt;
    //nameChord += this->alt + nameChord;
    std::cout << nameChord << std::endl;
}

void Chord::display()
{
//    for (int i=0; i< nb; i++)
//        std::cout << notes[i] << " ";
//    std::cout << std::endl;
}


bool checkName(std::string n)
{
   if NAME_IS(M)
   {
       return true;
   }
   else if NAME_IS(m)
   {
       return true;
   }
   else if NAME_IS(aug)
   {
       return true;
   }
   else if NAME_IS(dim)
   {
       return true;
   }
   else if NAME_IS(7)
   {
       return true;
   }
   else if NAME_IS(m7)
   {
       return true;
   }
   else if NAME_IS(M7)
   {
       return true;
   }
   else if NAME_IS(7b5)
   {
       return true;
   }
   else if NAME_IS(dim7)
   {
       return true;
   }
   else
   {
       return false;
   }
}
