#include "Scale.h"
#include "NaturalNote.h"
#include "SharpNote.h"
#include "FlatNote.h"
#include "SharpNote.h"

void Scale::setNotes()
{
    NaturalNote *ntmp = tonic->getNatural();
    ntmp->sort();
    notes.push_back(tonic);
    for (auto i : intervals)
    {
        notes.push_back(i.getNextSorted(tonic));
    }
}

Scale::Scale(Note *t, const std::string &n) : tonic(t), name(n)
{
    if (!n.compare("Major"))
    {
        intervals = {Interval("major second"),
                     Interval("major third"),
                     Interval("perfect fourth"),
                     Interval("perfect fifth"),
                     Interval("major sixth"),
                     Interval("major seventh")};
        setNotes();
        degChords.push_back(Chord(notes.at(0), "maj7"));
        degChords.push_back(Chord(notes.at(1), "m7"));
        degChords.push_back(Chord(notes.at(2), "m7"));
        degChords.push_back(Chord(notes.at(3), "maj7"));
        degChords.push_back(Chord(notes.at(4), "7"));
        degChords.push_back(Chord(notes.at(5), "m7"));
        degChords.push_back(Chord(notes.at(6), "m7b5"));
    }
    else if (!n.compare("Minor"))
    {
        intervals = {Interval("major second"),
                     Interval("minor third"),
                     Interval("perfect fourth"),
                     Interval("perfect fifth"),
                     Interval("minor sixth"),
                     Interval("minor seventh")};
        setNotes();
        degChords.push_back(Chord(notes.at(0), "m7"));
        degChords.push_back(Chord(notes.at(1), "m7b5"));
        degChords.push_back(Chord(notes.at(2), "maj7"));
        degChords.push_back(Chord(notes.at(3), "min7"));
        degChords.push_back(Chord(notes.at(4), "7"));
        degChords.push_back(Chord(notes.at(5), "maj77"));
        degChords.push_back(Chord(notes.at(6), "7"));
    }
    else
        throw E_SCALE_UNKNOWN;
}

int Scale::getDegree(Note *n)
{
    int deg = 0;
    for (auto note : notes)
    {
        if (n == note)
            return deg;
    }
    throw E_DEGREE_NOT_FOUND;
}

Note *Scale::getDegree(int deg)
{
    return notes.at(deg);
}

Chord Scale::getDegreeChord(Note *n)
{
    int i = 0;
    for (auto dc : degChords)
    {
        if (dc.getRoot() == n)
            return degChords.at(getDegree(n));
        throw E_DEGREE_NOT_FOUND;
    }
}

Chord Scale::getDegreeChord(int i)
{
    if (i >= degChords.size())
        throw E_DEGREE_NOT_FOUND;
    return degChords.at(i);
}

Scale::~Scale()
{
}

std::string Scale::display()
{
    std::string str;
    for (auto n : notes)
    {
        str += n->display() + " ";
    }
    return str;
}
