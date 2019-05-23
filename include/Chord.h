#ifndef _CHORD
#define _CHORD

#include "Triad.h"

#define CHORD_COUNT 9

extern const std::string chords[CHORD_COUNT];

class Chord
{
private:
    Note *root;
    Triad *t;
    Note *bass;
    int inversion;
    std::string name;

public:
    std::vector<Note *> notes;

private:
    Chord(Note *, const std::string &, Note *, int);

public:
    Chord(Note *, const std::string &, Note *);
    Chord(Note *, const std::string &, int);
    Chord(Note *, const std::string &);
    ~Chord();

    std::string getName(void);
    Triad *getTriad(void);
    Note *getRoot(void);

    std::string displayNotes(void);
};

#endif
