#include "NaturalNote.h"

NaturalNote::NaturalNote(std::string name, std::string fname, int semiToneCount)
{
    this->name = name; this->fname = fname; this->semiToneCount = semiToneCount;
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

SharpNote* NaturalNote::getSharpNote()
{
    return sn;
}

FlatNote* NaturalNote::getFlatNote()
{
    return fn;
}

int NaturalNote::getSemiToneCount()
{
    return semiToneCount;
}

void NaturalNote::initialize()
{
//    Note A = new NaturalNote();
}
