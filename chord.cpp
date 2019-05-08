#include "chord.h"

Chord::Chord(char root, char alt, std::string q) : Note(root,alt)
{
    notes.clear();
    notes.insert(notes.begin(),*this);
    setNameChord(q);
}

Chord::~Chord()
{
}


void Chord::buildChord()
{
    switch(nb)
    {
        case 3:

            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
    }
                
}

const std::string Chord::valid_chords()
{
    return "M, m, aug, dim, 7, m7, M7, 7b5, dim7";
}

void Chord::setNb(int n)
{
    nb = n;
}

void Chord::setNameChord(std::string q)
{
    nameChord.clear();
    nameChord = name;
    nameChord += alt;
    nameChord += q;
}

void Chord::displayNameChord()
{
    std::cout << "Chord : " << nameChord << std::endl;
}


int checkName(std::string n)
{
   if NAME_IS(M)
   {
       return 3;
   }
   else if NAME_IS(m)
   {
       return 3;
   }
   else if NAME_IS(aug)
   {
       return 3;
   }
   else if NAME_IS(dim)
   {
       return 3;
   }
   else if NAME_IS(7)
   {
       return 4;
   }
   else if NAME_IS(m7)
   {
       return 4;
   }
   else if NAME_IS(M7)
   {
       return 4;
   }
   else if NAME_IS(7b5)
   {
       return 4;
   }
   else if NAME_IS(dim7)
   {
       return 4;
   }
   else
   {
       return -1;
   }
}
