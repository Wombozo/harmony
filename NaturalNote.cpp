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

int NaturalNote::getNextSTNatural()
{
    return interSTNext;
}

void NaturalNote::sort()
{
    interSTNext = 2;
    NaturalNote *tmp = this;
   // std::cout << tmp->display() << tmp->semiToneNext << " ";
    do
    {
        tmp->following->interSTNext = tmp->interSTNext + tmp->semiToneNext;
        tmp = tmp->following;
    //    std::cout << tmp->display() << tmp->interSTNext << " ";
    } while (tmp->following != this);
}
