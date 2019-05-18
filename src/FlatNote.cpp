#include "FlatNote.h"

FlatNote::FlatNote(NaturalNote *n, DblFlatNote *f) : flat(f) 
{
    natural = n;
}

FlatNote::~FlatNote()
{
}

std::string FlatNote::display()
{
    return getNatural()->display() + "b";
}

int FlatNote::semiToneShift()
{
    return 1;
}
