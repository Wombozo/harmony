#ifndef _TRIAD
#define _TRIAD

#include "Note.h"
#include "Interval.h"

#include <vector>
#include <algorithm>

#define TRIAD_COUNT 8

extern const std::string triads[TRIAD_COUNT];

class Triad
{
private:
    Note *root;
    Note *bass;
    std::string name;
    std::string typeName;
    int inversion;
    std::vector<Interval> intervals;

public:
    std::vector<Note *> notes;

public:
    Triad() {}
    Triad(Note *, const std::string &);
    Triad(Note *, const std::string &, int);
    Triad(Note *, const std::string &, Note *);
    Triad(Note *, std::vector<Interval>);
    Triad(Note *, const std::string &, Note *, int);
    ~Triad();

    std::string getName(void);
    std::string getTypeName(void);
    Note *getRoot(void);
    Note *getBass(void);
    int getInversion(void);
    std::vector<Interval> getIntervals(void);

    //    void findTriad(const std::vector<Note *> &);
    std::string displayNotes(void);
};

#endif
