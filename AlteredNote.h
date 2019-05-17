#ifndef _AlteredNote
#define _AlteredNote

#include "Note.h"
#include "NaturalNote.h"

//class NaturalNote;

class AlteredNote : public virtual Note
{
public:
    NaturalNote *natural;

public:
    NaturalNote *getNatural(void);
};

#endif
