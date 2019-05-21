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
    Note *bass;

protected:
    std::string name;
    int inversion;

public:
    std::vector<Note *> notes;

protected:
    Triad(Note *, const std::string &, Note *, int);
    virtual void setInversion(void);

public:
    Triad() {}
    Triad(Note *, const std::string &);
    Triad(Note *, const std::string &, int);
    Triad(Note *, const std::string &, Note *);
    ~Triad();

    std::string getName(void);
    Note *getRoot(void);
    Note *getBass(void);

    //    void findTriad(const std::vector<Note *> &);
    std::string displayNotes(void);
};

#endif
