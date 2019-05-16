#ifndef _NaturalNote
#define _NaturalNote

#include "Note.h"

class SharpNote;
class FlatNote;

class NaturalNote : public virtual Note
{

private:
    std::string name;
    std::string fname;

public:
    NaturalNote *following;
    NaturalNote *preceding;
    SharpNote *sn;
    FlatNote *fn;
    int semiTone;

public:
    NaturalNote(std::string, std::string, int);
    ~NaturalNote();
    NaturalNote *getNatural(void);
    std::string getName(void);
    std::string getFName(void);
    std::string display(void);
    int semiToneCount(void);
};

#endif
