#ifndef _TRIAD
#define _TRIAD

#include "Note.h"
#include <vector>
#include <algorithm>

extern const std::string triads[];

class Triad
{
private:
    Note *root;
    std::string name;
    Note *bass;
    int inversion;

public:
    std::vector<Note*> notes;

private:
    Triad(Note *, const std::string &, Note *, int);

public:
    Triad(Note *, const std::string &);
    Triad(Note *, const std::string &, int);
    Triad(Note *, const std::string &, Note *);
    ~Triad();
    std::string getName(void);
    Note *getRoot(void);
    Note *getBass(void);
    int getInversion(void);

//    void findTriad(const std::vector<Note *> &);

    std::string displayNotes(void);
};

#endif
