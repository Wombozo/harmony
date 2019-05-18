#include "Chord.h"
#include "Interval.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

static void setNotes(Chord &c, std::vector<Interval> &intervals)
{
    c.getRoot()->getNatural()->sort();
    c.notes.push_back(c.getBass());
    if (c.getRoot() != c.getBass())
    {
        c.notes.push_back(c.getRoot());
    }
    Note *tmp;
    for (int k = 0; k < intervals.size(); k++)
    {
        tmp = intervals.at(k).getNextSorted(c.getRoot());
        c.notes.push_back(tmp);
    }
    if (c.getInversion() > c.notes.size() - 1)
        throw E_INVERSION;
    std::rotate(c.notes.begin(), c.notes.begin() + c.getInversion(), c.notes.end());
}

Chord::Chord(Note *n, const std::string &str) : Chord(n, str, n, 0)
{
}

Chord::Chord(Note *n, const std::string &str, int inv) : Chord(n, str, n, inv)
{
}

Chord::Chord(Note *n, const std::string &str, Note *b) : Chord(n, str, b, 0)
{
}

int Chord::getInversion()
{
    return inversion;
}

Note *Chord::getRoot()
{
    return root;
}
Note *Chord::getBass()
{
    return bass;
}

Chord::Chord(Note *n, const std::string &str, Note *b, int inv) : root(n), bass(b), inversion(inv)
{
    std::vector<Interval> intervals;
    intervals.clear();

    if (!str.compare(""))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("m"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("diminished"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("diminished fifth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("augmented"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("augmented fifth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("sus4"))
    {
        intervals.push_back(Interval("perfect fourth"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("7sus4"))
    {
        intervals.push_back(Interval("perfect fourth"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("sus2"))
    {
        intervals.push_back(Interval("major second"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("m7"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("7"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("maj7"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major seventh"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("minmaj7"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major seventh"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major sixth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("m6"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major sixth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("7b5"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("dim7"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("diminished seventh"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("m7b5"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("Ger6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("augmented sixth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("It6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("augmented sixth"));
        setNotes(*this, intervals);
    }
    else if (!str.compare("Fr6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("augmented sixth"));
        setNotes(*this, intervals);
    }
    else
    {
        throw E_CHORD_UNKNOWN;
    }
    name = n->display() + str;
    if (root != bass)
    {
        name += "/" + bass->display();
    }
    if (inversion)
        name += "/" + notes.at(0)->display();
}

void Chord::findChord(const std::vector<Note *> &notes)
{
    if (notes.size() > 5)
        throw E_CHORD_UNKNOWN;
}

std::string Chord::displayNotes()
{
    std::string str;
    for (int i = 0; i < notes.size(); i++)
    {
        str += notes.at(i)->display() + " ";
    }
    return str;
}

Chord::~Chord()
{
}

std::string Chord::getName()
{
    return name;
}
