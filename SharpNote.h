#ifndef _SharpNote
#define _SharpNote

#include "AlteredNote.h"

class DblSharpNote;

class SharpNote : public AlteredNote
{
private:
    DblSharpNote *sharp;

public:
    SharpNote(NaturalNote *, DblSharpNote *);
    ~SharpNote(void);
    std::string display(void);
    int semiToneCount(void);
};

#endif
