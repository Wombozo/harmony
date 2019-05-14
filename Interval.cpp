#include "Interval.h"

Interval::Interval(int t, int s)
{
    type = t;
    semitones = s;
}

Interval::~Interval()
{
}

std::string Interval::show()
{
    std::string str, stype, sst;
    switch (type)
    {
    case 2:
        stype = "second";
        sst = (semitones == 1) ? "minor" : (semitones == 2) ? "major" : (semitones == 3) ? "augmented" : throw 0;
        break;
    case 3:
        stype = "third";
        break;
    case 4:
        stype = "fourth";
        break;
    case 5:
        stype = "fifth";
        break;
    case 6:
        stype = "sixth";
        break;
    case 7:
        stype = "seventh";
        break;
    default:
        break;
    }
    return sst + " " + stype;
}