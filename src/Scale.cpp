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
        degChords.push_back(Chord(t, "maj7"));
        degChords.push_back(Chord(t, "m7"));
        degChords.push_back(Chord(t, "m7"));
        degChords.push_back(Chord(t, "maj7"));
        degChords.push_back(Chord(t, "7"));
        degChords.push_back(Chord(t, "m7"));
        degChords.push_back(Chord(t, "m7b5"));
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
        degChords.push_back(Chord(t, "m7"));
        degChords.push_back(Chord(t, "m7b5"));
        degChords.push_back(Chord(t, "maj7"));
        degChords.push_back(Chord(t, "min7"));
        degChords.push_back(Chord(t, "min7"));
        degChords.push_back(Chord(t, "maj77"));
        degChords.push_back(Chord(t, "7"));
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

static Chord _get_degree(int i, Scale s)
{
    return s.degChords.at(i);
}

template <typename T>
Chord Scale::getDegreeChord(T t)
{
    if (std::is_same<T, int>::value)
    {
        return degChords.at(t);
    }
    else if (std::is_same<T, Note *>::value)
    {
        int i = 0;
        for (auto dc : degChords)
        {
            if (dc.getRoot() == t)
                return degChords.at(getDegree(t));
            throw E_DEGREE_NOT_FOUND;
        }
    }
    else
    {
        throw E_TYPE;
    }
}

template Chord Scale::getDegreeChord<int>(int);
template Chord Scale::getDegreeChord<Note*>(Note*);

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
