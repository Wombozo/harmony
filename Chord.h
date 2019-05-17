#ifndef _CHORD
#define _CHORD

#include "Note.h"
#include "Interval.h"
#include <vector>

class Chord
{
private:
    Note *root;
    //TODO
    Note *bass;
    int nb;
    std::string name;
    std::vector<Interval> intervals;
    std::vector<Note *> notes;

private:
    void setNotes(void);

public:
    Chord(Note *, const std::string&);
    ~Chord();
    std::string getName(void);
    std::vector<Note *> getNotes;
    //TODO
    void findChord(const std::vector<Note*>&);

    std::string displayNotes(void);
};

#endif
