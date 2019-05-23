#ifndef _SCALE
#define _SCALE

#include "Note.h"
#include "Interval.h"
#include <vector>
#include "Chord.h"

class Scale
{
private:
    std::vector<Interval> intervals;

protected:
    Note *tonic;
    std::string name;
    std::vector<Note *> notes;

private:
    void setNotes(void);

public:
    Scale(Note *, const std::string &name);
    ~Scale();
    int getDegree(Note *);
    Note *getDegree(int);

    Chord getDegreeChord(Note*);
    Chord getDegreeChord(int);

    std::string display(void);
};

#endif
