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
    int semiToneCount;

public:
    NaturalNote *following;
    NaturalNote *preceding;
    SharpNote *sn;
    FlatNote *fn;

public:
    NaturalNote(std::string, std::string, int);
    ~NaturalNote();
    std::string getName(void);
    std::string getFName(void);
    int getSemiToneCount(void);
    std::string display(void);
};

#endif
