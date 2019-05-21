#ifndef _CHORD
#define _CHORD

#include "Triad.h"

class Chord : public Triad
{
private:
    Chord(Note *, const std::string &, Note *, int);

public:
    Chord(Note *, const std::string &);
    Chord(Note *, const std::string &, int);
    Chord(Note *, const std::string &, Note *);
    ~Chord();

    void setInversion(void);
};

#endif