#include "scale.h"

Scale::Scale(char n, char a, std::string t) : Note(n,a)
{
	 if (n == 'B' && a == '#')
      {
          name = 'C';
          alt = ' ';
      }
      else if (n == 'C' && a == 'b')
      {
          name = 'B';
          alt = ' ';
      }
      else if (n == 'E' && a == '#')
      {
          name = 'F';
          alt = ' ';
      }
      else if (n == 'F' && a == 'b')
      {
          name = 'E';
          alt = ' ';
      }
      else if (n == 'G' && a == 'b')
      {
          name = 'F';
          alt = '#';
      }
      else if (n == 'A' && a == '#')
      {
          name = 'B';
          alt = 'b';
      }
      else if (n == 'A' && a == 'b' && t == "Minor")
       {
          name = 'G';
          alt = '#';
       }
      else if (n == 'E' && a == 'b' && t == "Minor")
       {
          name = 'D';
          alt = '#';
       }
      else if (n == 'D' && a == 'b' && t == "Minor")
      {
          name = 'C';
          alt = '#'; 
      }
     else if (n == 'G' && a == '#' && t == "Major")
     {
         name = 'A';
         alt = 'b';
     }
     else if (n == 'C' && a == '#' && t == "Major")
     {
         name = 'D';
         alt = 'b';
     }

    type.assign(t);
    setIntervals();
    setDegrees();
}

Scale::~Scale()
{
}

std::string Scale::getType()
{
    return type;
}

std::vector<int> Scale::getIntervals()
{
    return intervals;
}

void Scale::setDegrees()
{
    std::vector<char> baseNotes = arrangeBaseNotes(name);
    degrees.clear();
    degrees.insert(degrees.begin(),*this);
    char alt = alterate(intervals[0], *this);
    Note n = *this;
    for (int i=1; i < nb; i++)
    {
        n = Note(baseNotes[i], alt);
        alt = alterate(intervals[i], n);
        degrees.insert(degrees.begin()+i,n);
    }
}

void Scale::setIntervals()
{
    if SCALE_IS(Major)
        intervals = {2, 2, 1, 2, 2, 2};
    else if SCALE_IS(Minor)
        intervals = {2, 1, 2, 2, 1, 2};
    nb = intervals.size()+1;
}

void Scale::display()
{
    std::cout << std::endl;
    std::cout << name << alt << " " << type << " scale :" << std::endl;
    displayDegrees();
}

void Scale::displayDegrees()
{
    for (int i=0; i<nb; i++)
        std::cout << degrees[i].display() << " ";
    std::cout << std::endl;
}

std::vector<Note> Scale::getDegrees()
{
    return degrees;
}
