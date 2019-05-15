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
        sst = (semitones == 8) ? "diminished" : (semitones == 9) ? "minor" : (semitones == 10) ? "major" : (semitones == 11) ? "augmented" : throw E_INTERVAL;
        break;
    case 8:
        stype = "octave";
        sst = (semitones == 12) ? "perfect" : throw E_INTERVAL;
        break;
    default:
        throw 0;
        break;
    }
    return sst + " " + stype;
}