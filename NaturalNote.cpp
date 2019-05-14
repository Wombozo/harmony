#include "NaturalNote.h"

NaturalNote::NaturalNote(std::string name, std::string fname, int semiToneCount, SharpNote *sn, FlatNote *fn)
{
    this->name = name;
    this->fname = fname;
    this->semiToneCount = semiToneCount;
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

SharpNote *NaturalNote::getSharpNote()
{
    return sn;
}

FlatNote *NaturalNote::getFlatNote()
{
    return fn;
}

int NaturalNote::getSemiToneCount()
{
    return semiToneCount;
}
