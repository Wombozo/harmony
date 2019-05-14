#include "FlatNote.h"

FlatNote::FlatNote(NaturalNote *n, DblFlatNote *flat)
{
    setNatural(n);
    this->flat = flat;
}

FlatNote::~FlatNote()
{
}


std::string FlatNote::display()
{
    return getNatural()->display()+"b";
}

int FlatNote::semiToneCount()
{
    return getNatural()->semiTone-1;
}