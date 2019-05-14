#ifndef _FlatNote
#define _FlatNote

#include "AlteredNote.h"

class DblFlatNote;

class FlatNote : public AlteredNote
{
private:
    DblFlatNote *flat;

public:
    FlatNote(NaturalNote *, DblFlatNote *);
    ~FlatNote(void);
    std::string display(void);
};

#endif
