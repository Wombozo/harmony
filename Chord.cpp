#include "Chord.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

//#define I_EQUALS(i, str) (!(intervals.at(i).getName().compare(str)))

void Chord::setNotes()
{
    std::cout << root->display() << std::endl;
    notes.push_back(root);
    for (int k=0; k < intervals.size(); k++)
    {
        int type = intervals.at(k).getType();
        int rst = intervals.at(k).getSemiTones();
        Note *tmp;
        SharpNote *stmp;
        FlatNote *ftmp;
        DblSharpNote *sstmp;
        DblFlatNote *fftmp;
        NaturalNote *ntmp = root->getNatural();
        // Get the natural note
        for (int i = 0; i < type - 1; i++)
        {
            ntmp = ntmp->following;
        }
      //  std::cout << "nat = "<<ntmp->getFName()<< " ";
      //  std::cout << "ntmp "<< ntmp->semiToneCount()<<" rst + rstc "<<rst<<" + "<<root->semiToneCount()<<std::endl;
        // Test for altered notes
        if (ntmp->semiToneCount() == rst + root->semiToneCount())
        {
            // Natural note;
            tmp = (Note *) ntmp;
        }
        else if(ntmp->semiToneCount() == rst + root->semiToneCount() - 1)
        {
            // Sharp note
            stmp = ntmp->sn;    
            tmp = (Note*) stmp;
        }
        else if((ntmp->semiToneCount() == rst + root->semiToneCount() + 1))
        {
            // Flat note
            ftmp = ntmp->fn;    
            tmp = (Note*) ftmp;
        }
        else if(ntmp->semiToneCount() == rst + root->semiToneCount() + 2)
        {
            // Double sharped note
            fftmp = ntmp->fn->flat;    
            tmp = (Note*) fftmp;
        }   
        else if(ntmp->semiToneCount()== rst + root->semiToneCount() - 2)
        {
            // Double flatted note
            sstmp = ntmp->sn->sharp;    
            tmp = (Note*) sstmp;
        }  
        else
        {
            std::cout<< ntmp->semiToneCount() +11 << " and "<<rst<< "+"<<root->semiToneCount()<<std::endl;
            throw E_CHORD_UNKNOWN;
        }
        std::cout << tmp->display() << std::endl;
        notes.push_back(tmp);
    }

//    tmp = root->getNatural();
//    type = intervals.at(1).getType();
//    for (int i = 0; i < type - 1; i++)
//    {
//        ntmp = ntmp->following;
//    }
//    //TODO: handles semitones before pushing back
//    std::cout << "fifth = " << tmp->display() << std::endl;
//    notes.push_back(ntmp);
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
//Chord::Chord(Note *n, std::vector<std::string> ints)
//{
//    root = n;
//    nb = (int)ints.size() + 1;
//    if (nb >= 4)
//        throw E_CHORD_LIMIT_SIZE;
//    else if (nb < 3)
//        throw E_CHORD_TOO_SMALL;
//    intervals;
//    intervals.clear();
//    for (int i = 0; i < ints.size(); i++)
//    {
//        Interval itinter(ints.at(i));
//        intervals.push_back(itinter);
//    }
//    // 3 notes chords
//    if (I_EQUALS(0, "major third") && I_EQUALS(1, "perfect fifth"))
//    {
//        name = "major";
//    }
//    else if (I_EQUALS(0, "minor third") && I_EQUALS(1, "perfect fifth"))
//    {
//        name = "minor";
//    }
//    else if (I_EQUALS(0, "minor third") && I_EQUALS(1, "diminished fifth"))
//    {
//        name = "diminished";
//    }
//    else if (I_EQUALS(0, "major third") && I_EQUALS(1, "augmented fifth"))
//    {
//        name = "augmented";
//    }
//    else if (I_EQUALS(0, "major second") && I_EQUALS(1, "perfect fifth"))
//    {
//        name = "sus2";
//    }
//    else if (I_EQUALS(0, "perfect fourth") && I_EQUALS(1, "perfect fifth"))
//    {
//        name = "sus4";
//    }
//    else if (I_EQUALS(0, "major third") && I_EQUALS(1, "augmented sixth"))
//    {
//        name = "It6";
//    }
//    else
//        throw E_CHORD_UNKNOWN;
//    if (nb == 4)
//    {
//        if ((name == "major") && I_EQUALS(2, "minor seventh"))
//        {
//            name = "7";
//        }
//        else if ((name == "major") && I_EQUALS(2, "major seventh"))
//        {
//            name = "maj7";
//        }
//        else if ((name == "minor") && I_EQUALS(2, "major seventh"))
//        {
//            name = "minmaj7";
//        }
//        else if ((name == "minor") && I_EQUALS(2, "minor seventh"))
//        {
//            name = "m7";
//        }
//        else if ((name == "diminished") && I_EQUALS(2, "seventh"))
//        {
//            name = "m7b5";
//        }
//        else if ((name == "diminished") && I_EQUALS(2, "diminished seventh"))
//        {
//            name = "dim7";
//        }
//        else if ((name == "sus4") && I_EQUALS(2, "minor seventh"))
//        {
//            name = "7sus4";
//        }
//        else if ((name == "major") && I_EQUALS(2, "augmented sixth"))
//        {
//            name = "Ger6";
//        }
//        else if (I_EQUALS(0, "major third") && I_EQUALS(1, "diminished fifth") && I_EQUALS(2, "augmented sixth"))
//        {
//            name = "Fr6";
//        }
//        else
//            throw E_CHORD_UNKNOWN;
//    }
//}

Chord::~Chord()
{
}

std::string Chord::getName()
{
    return name;
}
