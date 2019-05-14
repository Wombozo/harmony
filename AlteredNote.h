#ifndef _AlteredNote
#define _AlteredNote

#include "Note.h"

class NaturalNote;

class AlteredNote : public virtual Note
{
private:
    NaturalNote *natural;

protected:
    void setNatural(NaturalNote *);
};

#endif
