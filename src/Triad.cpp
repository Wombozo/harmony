#include "Triad.h"
#include "Interval.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

const std::string triads[TRIAD_COUNT] = {"", "m", "aug", "dim", "sus4", "sus2", "b5", "m#5"};

static void setNotes(Triad *c, Interval *intervals)
{
    c->getRoot()->getNatural()->sort();
    c->notes.push_back(c->getBass());
    if (c->getRoot() != c->getBass())
    {
        c->notes.push_back(c->getRoot());
    }
    Note *tmp;
    for (int k = 0; k < 2; k++)
    {
        tmp = intervals[k].getNextSorted(c->getRoot());
        c->notes.push_back(tmp);
    }
}

Triad::Triad(Note *n, const std::string &str) : Triad(n, str, n, 0)
{
}

Triad::Triad(Note *n, const std::string &str, int inv) : Triad(n, str, n, inv)
{
}

Triad::Triad(Note *n, const std::string &str, Note *b) : Triad(n, str, b, 0)
{
}

Triad::Triad(Note *n, const std::string &str, Note *b, int inv) : root(n), bass(b), inversion(inv)
{
    Interval *intervals;
    if (!str.compare(triads[0]))
    {
        // "" (major)
        Interval intervals[2] = {Interval("major third"), Interval("perfect fifth")};
        setNotes(this, intervals);
    }
    else if (!str.compare(triads[1]))
    {
        // "m"
        Interval intervals[2] = {Interval("minor third"), Interval("perfect fifth")};
        setNotes(this, intervals);
    }
    else if (!str.compare(triads[2]))
    {
        // "aug"
        Interval intervals[2] = {Interval("major third"), Interval("augmented fifth")};
        setNotes(this, intervals);
    }
    else if (!str.compare(triads[3]))
    {
        // "dim"
        Interval intervals[2] = {Interval("minor third"), Interval("diminished fifth")};
        setNotes(this, intervals);
    }
    else if (!str.compare(triads[4]))
    {
        // "sus4"
        Interval intervals[2] = {Interval("perfect fourth"), Interval("perfect fifth")};
        setNotes(this, intervals);
    }
    else if (!str.compare(triads[5]))
    {
        // "sus2"
        Interval intervals[2] = {Interval("major second"), Interval("perfect fifth")};
        setNotes(this, intervals);
    }
    else if (!str.compare(triads[6]))
    {
        // "b5"
        Interval intervals[2] = {Interval("major third"), Interval("diminished fifth")};
        setNotes(this, intervals);
    }
    else if (!str.compare(triads[7]))
    {
        // "m#5"
        Interval intervals[2] = {Interval("minor third"), Interval("augmented fifth")};
        setNotes(this, intervals);
    }
    else
        throw E_CHORD_UNKNOWN;

    if (inversion > 2)
        throw E_INVERSION;
    std::rotate(notes.begin(), notes.begin() + inversion, notes.end());

    name = n->display() + str;
    if (root != bass)
    {
        name += "/" + bass->display();
    }
    if (inversion)
    {
        name += "/" + notes.at(0)->display();
        notes.erase(notes.begin()+inversion);
    }
}

std::string Triad::displayNotes()
{
    std::string str;
    for (int i = 0; i < notes.size(); i++)
    {
        str += notes.at(i)->display() + " ";
    }
    return str;
}

Triad::~Triad()
{
}

std::string Triad::getName()
{
    return name;
}

Note *Triad::getRoot()
{
    return root;
}
Note *Triad::getBass()
{
    return bass;
}

int Triad::getInversion()
{
    return inversion;
}
