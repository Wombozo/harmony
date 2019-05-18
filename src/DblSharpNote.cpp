#include "DblSharpNote.h"

DblSharpNote::DblSharpNote(NaturalNote *n) 
{
    natural = n;
}

DblSharpNote::~DblSharpNote()
{
}

std::string DblSharpNote::display()
{
    return getNatural()->display() + "##";
}

int DblSharpNote::semiToneShift()
{
    return -2;
}
