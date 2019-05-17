#ifndef _CHORD
#define _CHORD

#include "Note.h"
#include "Interval.h"
#include <vector>
#include <algorithm>

class Chord
{
private:
    Note *root;
    int nb;
    std::string name;
    std::vector<Interval> intervals;
    std::vector<Note *> notes;
    Note *bass;
    int inversion;

private:
    void setNotes(void);
    Chord(Note *, const std::string &, Note *, int);

public:
    Chord(Note *, const std::string &);
    Chord(Note *, const std::string &, int);
    Chord(Note *, const std::string &, Note *);
    ~Chord();
    std::string getName(void);
    std::vector<Note *> getNotes;
    void findChord(const std::vector<Note *> &);

    std::string displayNotes(void);
};

#endif
