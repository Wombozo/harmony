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