#include "Chord.h"
#include "NaturalNote.h"

//#define I_EQUALS(i, str) (!(intervals.at(i).getName().compare(str)))

void Chord::setNotes(std::vector<Interval> ints)
{
    notes.push_back(root);
    int type = ints.at(0).getType();
    NaturalNote *tmp = root->getNatural();
    std::cout << root->getNatural()->display() << std::endl;
    for (int i = 0; i < type - 1; i++)
    {
        tmp = tmp->following;
    }
    notes.push_back(tmp);
    std::cout << tmp->display() << std::endl;
    tmp = root->getNatural();
    type = ints.at(1).getType();
    for (int i = 0; i < type - 1; i++)
    {
        tmp = tmp->following;
    }
    std::cout << tmp->display() << std::endl;
}

Chord::Chord(Note *n, std::string str) : root(n), name(str)
{
    std::vector<Interval> ints;
    if (!name.compare("major"))
    {
        ints.push_back(Interval("major third"));
        ints.push_back(Interval("perfect fifth"));
        setNotes(ints);
    }
    else if (!name.compare("minor"))
    {
        ints.push_back(Interval("minor third"));
        ints.push_back(Interval("perfect fifth"));
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
