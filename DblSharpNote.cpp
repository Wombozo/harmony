#include "DblSharpNote.h"

DblSharpNote::DblSharpNote(NaturalNote *n)
{
    setNatural(n);
}

DblSharpNote::~DblSharpNote()
{
}

std::string DblSharpNote::display()
{
    return getNatural()->display()+"##";
}

int DblSharpNote::semiToneCount()
{
    return getNatural()->semiTone+2;
}