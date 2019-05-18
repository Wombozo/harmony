#include "Chord.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

void Chord::setNotes()
{
    root->getNatural()->sort();
    notes.push_back(bass);
    if (root != bass)
    {
        notes.push_back(root);
    }
    Note *tmp;
    for (int k = 0; k < intervals.size(); k++)
    {
        tmp = intervals.at(k).getNextSorted(root);
        notes.push_back(tmp);
    }
    if (inversion > notes.size() - 1)
        throw E_INVERSION;
    std::rotate(notes.begin(), notes.begin() + inversion, notes.end());
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

Chord::Chord(Note *n, const std::string &str, Note *b, int inv) : root(n), bass(b), inversion(inv)
{
    intervals.clear();
    if (!str.compare(""))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes();
    }
    else if (!str.compare("m"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes();
    }
    else if (!str.compare("diminished"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("diminished fifth"));
        setNotes();
    }
    else if (!str.compare("augmented"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("augmented fifth"));
        setNotes();
    }
    else if (!str.compare("sus4"))
    {
        intervals.push_back(Interval("perfect fourth"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes();
    }
    else if (!str.compare("7sus4"))
    {
        intervals.push_back(Interval("perfect fourth"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes();
    }
    else if (!str.compare("sus2"))
    {
        intervals.push_back(Interval("major second"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes();
    }
    else if (!str.compare("m7"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes();
    }
    else if (!str.compare("7"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes();
    }
    else if (!str.compare("maj7"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major seventh"));
        setNotes();
    }
    else if (!str.compare("minmaj7"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major seventh"));
        setNotes();
    }
    else if (!str.compare("6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major sixth"));
    }
    else if (!str.compare("m6"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major sixth"));
    }
    else if (!str.compare("7b5"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes();
    }
    else if (!str.compare("dim7"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("diminished seventh"));
        setNotes();
    }
    else if (!str.compare("m7b5"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes();
    }
    else if (!str.compare("Ger6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("augmented sixth"));
        setNotes();
    }
    else if (!str.compare("It6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("augmented sixth"));
        setNotes();
    }
    else if (!str.compare("Fr6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("augmented sixth"));
        setNotes();
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
