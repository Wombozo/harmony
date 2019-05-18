#include "Interval.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

Note *Interval::getNext(Note *a)
{
    NaturalNote *ntmp = a->getNatural();
    ntmp->sort();
    getNextSorted(a);
}
Note *Interval::getNextSorted(Note *a)
{

    Note *tmp;
    // Get the natural note
    NaturalNote *ntmp = a->getNatural();
    for (int i = 0; i < type - 1; i++)
    {
        ntmp = ntmp->next;
    }
    // Test for altered notes
    SharpNote *stmp;
    FlatNote *ftmp;
    DblSharpNote *sstmp;
    DblFlatNote *fftmp;

    if (getSemiTones() == a->semiToneShift() + ntmp->getNextSTNatural())
    {
        tmp = (Note *)ntmp;
    }
    else if (getSemiTones() == a->semiToneShift() + ntmp->getNextSTNatural() + 1)
    {
        tmp = (Note *)ntmp->sn;
    }
    else if (getSemiTones() == a->semiToneShift() + ntmp->getNextSTNatural() - 1)
    {
        tmp = (Note *)ntmp->fn;
    }
    else if (getSemiTones() == a->semiToneShift() + ntmp->getNextSTNatural() + 2)
    {
        tmp = (Note *)ntmp->sn->sharp;
    }
    else if (getSemiTones() == a->semiToneShift() + ntmp->getNextSTNatural() - 2)
    {
        tmp = (Note *)ntmp->fn->flat;
    }
    else
    {
        throw E_INTERVAL;
    }
    return tmp;
}

Interval::Interval(std::string str)
{
    if (!str.compare("minor second"))
    {
        type = 2;
        semitones = 1;
    }
    else if (!str.compare("major second"))
    {
        type = 2;
        semitones = 2;
    }
    else if (!str.compare("augmented second"))
    {
        type = 2;
        semitones = 3;
    }
    else if (!str.compare("diminished third"))
    {
        type = 3;
        semitones = 2;
    }
    else if (!str.compare("minor third"))
    {
        type = 3;
        semitones = 3;
    }
    else if (!str.compare("major third"))
    {
        type = 3;
        semitones = 4;
    }
    else if (!str.compare("augmented third"))
    {
        type = 3;
        semitones = 5;
    }
    else if (!str.compare("diminished fourth"))
    {
        type = 4;
        semitones = 4;
    }
    else if (!str.compare("perfect fourth"))
    {
        type = 4;
        semitones = 5;
    }
    else if (!str.compare("augmented fourth"))
    {
        type = 4;
        semitones = 6;
    }
    else if (!str.compare("diminished fifth"))
    {
        type = 5;
        semitones = 6;
    }
    else if (!str.compare("perfect fifth"))
    {
        type = 5;
        semitones = 7;
    }
    else if (!str.compare("augmented fifth"))
    {
        type = 5;
        semitones = 8;
    }
    else if (!str.compare("diminished sixth"))
    {
        type = 6;
        semitones = 7;
    }
    else if (!str.compare("minor sixth"))
    {
        type = 6;
        semitones = 8;
    }
    else if (!str.compare("major sixth"))
    {
        type = 6;
        semitones = 9;
    }
    else if (!str.compare("augmented sixth"))
    {
        type = 6;
        semitones = 10;
    }
    else if (!str.compare("diminished seventh"))
    {
        type = 7;
        semitones = 9;
    }
    else if (!str.compare("minor seventh"))
    {
        type = 7;
        semitones = 10;
    }
    else if (!str.compare("major seventh"))
    {
        type = 7;
        semitones = 11;
    }
    else
    {
        throw E_INTERVAL;
    }
    name = str;
}

Interval::~Interval()
{
}

std::string Interval::getName()
{
    return name;
}

int Interval::getType()
{
    return type;
}

int Interval::getSemiTones()
{
    return semitones;
}