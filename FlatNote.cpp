#include "FlatNote.h"

FlatNote::FlatNote(NaturalNote *n, DblFlatNote *flat)
{
    setNatural(n);
    this->flat = flat;
}

FlatNote::~FlatNote()
{
}
