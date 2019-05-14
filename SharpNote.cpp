#include "SharpNote.h"

SharpNote::SharpNote(NaturalNote *n, DblSharpNote *flat)
{
    setNatural(n);
    this->flat = flat;
}

SharpNote::~SharpNote()
{
}
