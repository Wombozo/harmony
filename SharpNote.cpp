#include "SharpNote.h"

SharpNote::SharpNote(NaturalNote *n, DblSharpNote *sharp)
{
    setNatural(n);
    this->sharp = sharp;
}

SharpNote::~SharpNote()
{
}

std::string SharpNote::display()
{
    return getNatural()->display()+"#";
}

int SharpNote::semiToneCount()
{
    return 1;
}