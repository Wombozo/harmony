#include "NaturalNote.h"

NaturalNote::NaturalNote(std::string name, std::string fname, int semiToneNext)
{
    this->name = name;
    this->fname = fname;
    this->semiToneNext = semiToneNext;
    this->sn = sn;
    this->fn = fn;
}

int NaturalNote::gS()
{
    return tmpST;
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

void NaturalNote::sort()
{
    NaturalNote *tmp = this->following;
    this->tmpST = 2;
    int count=2;
    while (tmp->following != this)
    {
        tmp->tmpST = count + tmp->semiToneNext;
        tmp = tmp->following;
    }
}
