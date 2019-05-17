#include "Chord.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

//#define I_EQUALS(i, str) (!(intervals.at(i).getName().compare(str)))

void Chord::setNotes()
{
    std::cout << root->display() << name << " chord : " << std::endl;
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
        std::cout<<"ntmp->nextSTNATURAL "<<ntmp->getNextSTNatural()<<std::endl;
        std::cout<<"stIntervals = "<<rst<<std::endl;

        if (rst == root->semiToneShift() + ntmp->getNextSTNatural())
        {
            tmp = (Note *)ntmp;
            std::cout<<__LINE__<<std::endl;
        }
        else if (rst == root->semiToneShift() + ntmp->getNextSTNatural() + 1)
        {
            tmp = (Note *)ntmp->sn;
            std::cout<<__LINE__<<std::endl;
        }
        else if (rst == root->semiToneShift() + ntmp->getNextSTNatural() - 1)
        {
            tmp = (Note *)ntmp->fn;
            std::cout<<__LINE__<<std::endl;
        }
        else if (rst == root->semiToneShift() + ntmp->getNextSTNatural() + 2)
        {
            tmp = (Note *)ntmp->sn->sharp;
            std::cout<<__LINE__<<std::endl;
        }
        else if (rst == root->semiToneShift() + ntmp->getNextSTNatural() - 2)
        {
            tmp = (Note *)ntmp->fn->flat;
            std::cout<<__LINE__<<std::endl;
        }
        else
        {
            throw E_CHORD_UNKNOWN;
        }
        notes.push_back(tmp);
    }
}

Chord::Chord(Note *n, std::string str) : root(n), name(str)
{
    intervals.clear();
    if (!name.compare("major"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes();
    }
    else if (!name.compare("minor"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes();
    }
    else if (!name.compare("diminished"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("diminished fifth"));
        setNotes();
    }
    else if (!name.compare("augmented"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("augmented fifth"));
        setNotes();
    }
    else if (!name.compare("sus4"))
    {
        intervals.push_back(Interval("perfect fourth"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes();
    }
    else if (!name.compare("sus2"))
    {
        intervals.push_back(Interval("major second"));
        intervals.push_back(Interval("perfect fifth"));
        setNotes();
    }
    else if (!name.compare("m7"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes();
    }
    else if (!name.compare("7"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes();
    }
    else if (!name.compare("maj7"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major seventh"));
        setNotes();
    }
    else if (!name.compare("minmaj7"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major seventh"));
        setNotes();
    }
    else if (!name.compare("6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major sixth"));
    }
    else if (!name.compare("m6"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("major sixth"));
    }
    else if (!name.compare("7b5"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes();
    }
    else if (!name.compare("dim7"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("diminished seventh"));
        setNotes();
    }
    else if (!name.compare("m7b5"))
    {
        intervals.push_back(Interval("minor third"));
        intervals.push_back(Interval("diminished fifth"));
        intervals.push_back(Interval("minor seventh"));
        setNotes();
    }
    else if (!name.compare("Ger6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("perfect fifth"));
        intervals.push_back(Interval("augmented sixth"));
        setNotes();
    }
    else if (!name.compare("It6"))
    {
        intervals.push_back(Interval("major third"));
        intervals.push_back(Interval("augmented sixth"));
        setNotes();
    }
    else if (!name.compare("Fr6"))
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
