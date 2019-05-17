#include "Chord.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

void Chord::setNotes()
{
    root->getNatural()->sort();
    notes.push_back(root);
    for (int k = 0; k < intervals.size(); k++)
    {
        int type = intervals.at(k).getType();
        int rst = intervals.at(k).getSemiTones();
        Note *tmp;
        // Get the natural note
        NaturalNote *ntmp = root->getNatural();
        for (int i = 0; i < type - 1; i++)
        {
            ntmp = ntmp->next;
        }
        // Test for altered notes
        SharpNote *stmp;
        FlatNote *ftmp;
        DblSharpNote *sstmp;
        DblFlatNote *fftmp;

        if (rst == root->semiToneShift() + ntmp->getNextSTNatural())
        {
            tmp = (Note *)ntmp;
        }
        else if (rst == root->semiToneShift() + ntmp->getNextSTNatural() + 1)
        {
            tmp = (Note *)ntmp->sn;
        }
        else if (rst == root->semiToneShift() + ntmp->getNextSTNatural() - 1)
        {
            tmp = (Note *)ntmp->fn;
        }
        else if (rst == root->semiToneShift() + ntmp->getNextSTNatural() + 2)
        {
            tmp = (Note *)ntmp->sn->sharp;
        }
        else if (rst == root->semiToneShift() + ntmp->getNextSTNatural() - 2)
        {
            tmp = (Note *)ntmp->fn->flat;
        }
        else
        {
            throw E_CHORD_UNKNOWN;
        }
        notes.push_back(tmp);
    }
}

Chord::Chord(Note *n, std::string str) : root(n)
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
    name = n->display()+str;
}

void Chord::findChord(const std::vector<Note*> &notes)
{

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
