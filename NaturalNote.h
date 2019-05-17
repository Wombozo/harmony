#ifndef _NaturalNote
#define _NaturalNote

#include "Note.h"

#define BASE_ST 2

class SharpNote;
class FlatNote;

class NaturalNote : public virtual Note
{

private:
    std::string name;
    std::string fname;

public:
    NaturalNote *next;
    NaturalNote *previous;
    SharpNote *sn;
    FlatNote *fn;
    int semiToneOrdered;
    int semiToneNext;

public:
    NaturalNote(const std::string&, const std::string&, int);
    ~NaturalNote();
    NaturalNote *getNatural(void);
    std::string getName(void);
    std::string getFName(void);
    std::string display(void);
    int semiToneShift(void);
    int getNextSTNatural(void);
    void sort();
};

#endif
