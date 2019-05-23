#include "Chord.h"
#include "Interval.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

const std::string chords[CHORD_COUNT] = {"7", "maj7", "6", "m7", "minmaj7", "m6", "m7b5", "7b5", "dim7"};

Chord::Chord(Note *n, const std::string &str) : Chord(n, str, n, 0)
{
}

Chord::Chord(Note *n, const std::string &str, int inv) : Chord(n, str, n, inv)
{
}

Chord::Chord(Note *n, const std::string &str, Note *b) : Chord(n, str, b, 0)
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

Chord::Chord(Note *n, const std::string &str, Note *b, int inv) : bass(b), inversion(inv)
{
    const std::string *ret = std::find(std::begin(triads), std::end(triads), str);
    if (ret != std::end(triads))
    {
        t = new Triad(n, str, b, inv);
        root = t->getRoot();
        bass = t->getBass();
        inversion = t->getInversion();
        name = t->getName();
        notes = t->notes;
    }
    else
    {
        if (!str.compare(chords[0]))
        {
            t = new Triad(n, "", b);
            notes = t->notes;
            notes.push_back(Interval("minor seventh").getNextSorted(n));
        }
        else if (!str.compare(chords[1]))
        {
            t = new Triad(n, "", b);
            notes = t->notes;
            notes.push_back(Interval("major seventh").getNextSorted(n));
        }
        else if (!str.compare(chords[2]))
        {
            t = new Triad(n, "", b);
            notes = t->notes;
            notes.push_back(Interval("major sixth").getNextSorted(n));
        }
        else if (!str.compare(chords[3]))
        {
            t = new Triad(n, "m", b);
            notes = t->notes;
            notes.push_back(Interval("minor seventh").getNextSorted(n));
        }
        else if (!str.compare(chords[4]))
        {
            t = new Triad(n, "m", b);
            notes = t->notes;
            notes.push_back(Interval("major seventh").getNextSorted(n));
        }
        else if (!str.compare(chords[5]))
        {
            t = new Triad(n, "m", b);
            notes = t->notes;
            notes.push_back(Interval("major sixth").getNextSorted(n));
        }
        else if (!str.compare(chords[6]))
        {
            t = new Triad(n, "dim", b);
            notes = t->notes;
            notes.push_back(Interval("minor seventh").getNextSorted(n));
        }
        else if (!str.compare(chords[7]))
        {
            t = new Triad(n, "b5", b);
            notes = t->notes;
            notes.push_back(Interval("minor seventh").getNextSorted(n));
        }
        else if (!str.compare(chords[8]))
        {
            t = new Triad(n, "dim", b);
            notes = t->notes;
            notes.push_back(Interval("diminished seventh").getNextSorted(n));
        }
        else
            throw E_CHORD_UNKNOWN;
        root = t->getRoot();
        if (inv > 3 | inv < 0)
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
        }
    }
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

Triad *Chord::getTriad()
{
    return t;
}

std::string Chord::getName()
{
    return name;
}

Chord::~Chord()
{
    delete (t);
}

Note *Chord::getRoot()
{
    return root;
}
