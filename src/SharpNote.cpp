#include "SharpNote.h"

SharpNote::SharpNote(NaturalNote *n, DblSharpNote *s) : sharp(s)
{
    natural = n;
}

SharpNote::~SharpNote()
{
}

std::string SharpNote::display()
{
    return getNatural()->display() + "#";
}

int SharpNote::semiToneShift()
{
    return -1;
}
