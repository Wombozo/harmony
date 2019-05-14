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
    SharpNote *sn;
    FlatNote *fn;

public:
    NaturalNote *following;
    NaturalNote *preceding;

public:
    NaturalNote(std::string, std::string, int, SharpNote *, FlatNote *);
    ~NaturalNote();
    std::string getName(void);
    std::string getFName(void);
    SharpNote *getSharpNote(void);
    FlatNote *getFlatNote(void);
    int getSemiToneCount(void);
};

#endif
