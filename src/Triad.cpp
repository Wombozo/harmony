#include "Triad.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

const std::string triads[TRIAD_COUNT] = {"", "m", "aug", "dim", "sus4", "sus2", "b5", "m#5"};

static void setNotes(Triad *c, std::vector<Interval> *intervals)
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
        tmp = intervals->at(k).getNextSorted(c->getRoot());
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
    // Remove the notes if the bass is one of the notes of the chord
    if (b != n)
    {
        auto foundIt = std::find(notes.rbegin(), notes.rend(), b);
        if (foundIt != notes.rend())
        {
            auto toRemove = --(foundIt.base());
            notes.erase(toRemove);
        }
    }
}

Triad::Triad(Note *n, std::vector<Interval> ints) : root(n), bass(n), inversion(0)
{
    std::string str;
    if (ints.size() < 2)
        throw E_CHORD_UNKNOWN;
    
    intervals = {ints.at(0), ints.at(1)};
    if (!ints.at(0).getName().compare("major third") && !ints.at(1).getName().compare("perfect fifth"))
    {
        str = triads[0];
    }
    else if (!ints.at(0).getName().compare("minor third") && !ints.at(1).getName().compare("perfect fifth"))
    {
        str = triads[1];
    }
    else if (!ints.at(0).getName().compare("major third") && !ints.at(1).getName().compare("augmtented fifth"))
    {
        str = triads[2];
    }
    else if (!ints.at(0).getName().compare("minor third") && !ints.at(1).getName().compare("diminished fifth"))
    {
        str = triads[3];
    }
    else if (!ints.at(0).getName().compare("perfect fourth") && !ints.at(1).getName().compare("perfect fifth"))
    {
        str = triads[4];
    }
    else if (!ints.at(0).getName().compare("major second") && !ints.at(1).getName().compare("perfect fifth"))
    {
        str = triads[5];
    }
    else if (!ints.at(0).getName().compare("major third") && !ints.at(1).getName().compare("diminished fifth"))
    {
        str = triads[6];
    }
    else if (!ints.at(0).getName().compare("minor third") && !ints.at(1).getName().compare("augmented fifth"))
    {
        str = triads[7];
    }
    else
        throw E_CHORD_UNKNOWN;
    setNotes(this, &ints);
    name = n->display() + str;
    typeName = str;
}

Triad::Triad(Note *n, const std::string &str, Note *b, int inv) : root(n), bass(b), inversion(inv)
{
    if (!str.compare(triads[0]))
    {
        // "" (major)
        intervals = {std::string("major third"), std::string("perfect fifth")};
        setNotes(this, &intervals);
    }
    else if (!str.compare(triads[1]))
    {
        // "m"
        intervals = {std::string("minor third"), std::string("perfect fifth")};
        setNotes(this, &intervals);
    }
    else if (!str.compare(triads[2]))
    {
        // "aug"
        intervals = {std::string("major third"), std::string("augmented fifth")};
        setNotes(this, &intervals);
    }
    else if (!str.compare(triads[3]))
    {
        // "dim"
        intervals = {std::string("minor third"), std::string("diminished fifth")};
        setNotes(this, &intervals);
    }
    else if (!str.compare(triads[4]))
    {
        // "sus4"
        intervals = {std::string("perfect fourth"), std::string("perfect fifth")};
        setNotes(this, &intervals);
    }
    else if (!str.compare(triads[5]))
    {
        // "sus2"
        intervals = {std::string("major second"), std::string("perfect fifth")};
        setNotes(this, &intervals);
    }
    else if (!str.compare(triads[6]))
    {
        // "b5"
        intervals = {std::string("major third"), std::string("diminished fifth")};
        setNotes(this, &intervals);
    }
    else if (!str.compare(triads[7]))
    {
        // "m#5"
        intervals = {std::string("minor third"), std::string("augmented fifth")};
        setNotes(this, &intervals);
    }
    else
        throw E_CHORD_UNKNOWN;

    if (inversion > 2 | inversion < 0)
        throw E_INVERSION;
    std::rotate(notes.begin(), notes.begin() + inversion, notes.end());

    name = n->display() + str;
    typeName = str;
    if (root != bass)
    {
        name += "/" + bass->display();
    }
    if (inversion)
    {
        name += "/" + notes.at(0)->display();
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

std::vector<Interval> Triad::getIntervals()
{
    return intervals;
}

int Triad::getInversion()
{
    return inversion;
}

std::string Triad::getTypeName()
{
    return typeName;
}