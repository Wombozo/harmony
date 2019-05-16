#include "NaturalNote.h"

NaturalNote::NaturalNote(std::string name, std::string fname, int semiToneNext)
{
    this->name = name;
    this->fname = fname;
    this->semiToneNext = semiToneNext;
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
    return 0;
}

NaturalNote *NaturalNote::getNatural()
{
    return this;
}
