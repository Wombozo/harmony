#include "Interval.h"

Interval::Interval(int t, int s)
{
    type = t;
    semitones = s;
    std::string stype, sst;
    switch (type)
    {
    case 2:
        stype = "second";
        sst = (semitones == 1) ? "minor" : (semitones == 2) ? "major" : (semitones == 3) ? "augmented" : throw E_INTERVAL;
        break;
    case 3:
        stype = "third";
        sst = (semitones == 2) ? "diminished" : (semitones == 3) ? "minor" : (semitones == 4) ? "major" : (semitones == 5) ? "augmented" : throw E_INTERVAL;
        break;
    case 4:
        stype = "fourth";
        sst = (semitones == 4) ? "diminished" : (semitones == 5) ? "perfect" : (semitones == 6) ? "augmented" : throw E_INTERVAL;
        break;
    case 5:
        stype = "fifth";
        sst = (semitones == 6) ? "diminished" : (semitones == 7) ? "perfect" : (semitones == 8) ? "augmented" : throw E_INTERVAL;
        break;
    case 6:
        stype = "sixth";
        sst = (semitones == 7) ? "diminished" : (semitones == 8) ? "minor" : (semitones == 9) ? "major" : (semitones == 10) ? "augmented" : throw E_INTERVAL;
        break;
    case 7:
        stype = "seventh";
        sst = (semitones == 9) ? "diminished" : (semitones == 10) ? "minor" : (semitones == 11) ? "major" : (semitones == 11) ? "augmented" : throw E_INTERVAL;
        break;
    case 8:
        stype = "octave";
        sst = (semitones == 12) ? "perfect" : throw E_INTERVAL;
        break;
    default:
        throw 0;
        break;
    }
    name = sst + " " + stype;
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