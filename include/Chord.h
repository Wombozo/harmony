#ifndef _CHORD
#define _CHORD

#include "Note.h"
#include <vector>
#include <algorithm>

class Chord
{
private:
    Note *root;
    int nb;
    std::string name;
    Note *bass;
    int inversion;

public:
    std::vector<Note *> notes;

private:
    Chord(Note *, const std::string &, Note *, int);

public:
    Chord(Note *, const std::string &);
    Chord(Note *, const std::string &, int);
    Chord(Note *, const std::string &, Note *);
    ~Chord();
    std::string getName(void);
    Note *getRoot(void);
    Note *getBass(void);
    int getInversion(void);

    void findChord(const std::vector<Note *> &);

    std::string displayNotes(void);
};

#endif
