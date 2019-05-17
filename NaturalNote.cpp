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

void NaturalNote::sort()
{
    tmpST = 2;
    NaturalNote *tmp = this;
    do
    {
        tmp->tmpST = tmp->tmpST + tmp->semiToneNext;
        std::cout<< tmp->tmpST + tmp->semiToneNext<<std::endl;
        tmp = tmp->following;
        std::cout<<tmp->display()<<tmp->tmpST<< " ";
        std::cout << tmp->semiToneNext<<std::endl;
    }while (tmp->following != this);
}
