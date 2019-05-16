#include "NaturalNote.h"

NaturalNote::NaturalNote(std::string name, std::string fname, int semiToneCount)
{
    this->name = name;
    this->fname = fname;
    this->semiTone = semiToneCount;
    this->sn = sn;
    this->fn = fn;
}

NaturalNote::~NaturalNote()
{
}

std::string NaturalNote::getName()
{
    return name;
}

std::string NaturalNote::getFName()
{
    return fname;
}

std::string NaturalNote::display()
{
    return getName();
}

int NaturalNote::semiToneCount()
{
    return semiTone;
}

NaturalNote *NaturalNote::getNatural()
{
    return this;
}

void NaturalNote::rotateST()
{
    if (this->semiTone != BASE_STONE)
    {
        NaturalNote *prev_baseNote = following;
        while (prev_baseNote->semiTone != BASE_STONE)
        {
            prev_baseNote = prev_baseNote->following;
        }
        std::cout<<"Note : " << prev_baseNote->fname<<std::endl;
        //Note *prev_baseNote = (Note *) tmp;
        NaturalNote *new_note = this;
        while (prev_baseNote->following != prev_baseNote)
        {
            new_note->semiTone = prev_baseNote->semiTone;
            new_note = new_note->following;
            prev_baseNote = prev_baseNote->following;
        }
        std::cout << ":::: " << this->semiTone << " :::"<<std::endl;

    }
}
