#ifndef _DblFlatNote
#define _DblFlatNote

#include "AlteredNote.h"

class DblFlatNote : public AlteredNote
{
public:
    DblFlatNote(NaturalNote *);
    ~DblFlatNote(void);
    std::string display(void);
    int semiToneCount(void);
};

#endif