#ifndef _NaturalNote
#define _NaturalNote

#include "Note.h"

#define BASE_ST 0

class SharpNote;
class FlatNote;

class NaturalNote : public virtual Note
{

private:
    std::string name;
    std::string fname;
    int semiToneOrdered;
    int semiToneNext;

public:
    NaturalNote *next;
    NaturalNote *previous;
    SharpNote *sn;
    FlatNote *fn;

public:
    NaturalNote(const std::string &, const std::string &, int);
    ~NaturalNote();

    std::string getName(void);
    std::string getFName(void);
    std::string display(void);
    NaturalNote *getNatural(void);

    int getNextSTNatural(void);
    int semiToneShift(void);
    void sort();
};

#endif
