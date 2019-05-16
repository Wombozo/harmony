#ifndef _CHORD
#define _CHORD

#include "Note.h"
#include "Interval.h"
#include <vector>
#include <tuple>

class Chord
{
private:
    Note *root;
    int nb;
    std::string name;
    std::vector<Interval> intervals;
    std::vector<Note*> notes;

private:
    void setNotes(std::vector<Interval>);

public:
    Chord(Note *, std::string);
    //    Chord(Note*, std::vector<std::string>);
    ~Chord();
    std::string getName(void);
};

#endif