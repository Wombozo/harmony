#include "DblFlatNote.h"

DblFlatNote::DblFlatNote(NaturalNote *n)
{
    setNatural(n);
}

DblFlatNote::~DblFlatNote()
{
}
std::string DblFlatNote::display()
{
    return getNatural()->display()+"bb";
}

int DblFlatNote::semiToneCount()
{
    return getNatural()->semiTone-2;
}