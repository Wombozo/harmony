#ifndef _AlteredNote
#define _AlteredNote

#include "Note.h"
#include "NaturalNote.h"

//class NaturalNote;

class AlteredNote : public virtual Note
{
private:
    NaturalNote *natural;

protected:
    void setNatural(NaturalNote *);
    NaturalNote *getNatural(void);
    //int semiToneReCount(void);
};

#endif
