#ifndef _SharpNote
#define _SharpNote

#include "AlteredNote.h"

class DblSharpNote;

class SharpNote : public AlteredNote
{
private:
    DblSharpNote *flat;

public:
    SharpNote(NaturalNote *, DblSharpNote *);
    ~SharpNote(void);
};

#endif
