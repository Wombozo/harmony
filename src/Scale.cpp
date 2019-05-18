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
    }
    else
        throw E_SCALE_UNKNOWN;
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