#include "AlteredNote.h"

void AlteredNote::setNatural(NaturalNote *n)
{
    natural = n;
}

NaturalNote *AlteredNote::getNatural()
{
    return natural;
}
