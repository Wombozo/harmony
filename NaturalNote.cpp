#include "NaturalNote.h"

NaturalNote::NaturalNote(const std::string &n, const std::string &fn, int smTN) : name(n), fname(fn), semiToneNext(smTN) 
{
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

int NaturalNote::semiToneShift()
{
    return 0;
}

NaturalNote *NaturalNote::getNatural()
{
    return this;
}

int NaturalNote::getNextSTNatural()
{
    return semiToneOrdered;
}

void NaturalNote::sort()
{
    semiToneOrdered = BASE_ST;
    std::cout<<this->display()<<this->semiToneOrdered << " ";
    NaturalNote *nTmp = this;
    do 
    {
    nTmp->next->semiToneOrdered = nTmp->semiToneNext + nTmp->semiToneOrdered;
    nTmp = nTmp->next;
    std::cout<<nTmp->display()<<nTmp->semiToneOrdered<< " ";

    } while (nTmp != this->previous);
    std::cout<<std::endl;
}
