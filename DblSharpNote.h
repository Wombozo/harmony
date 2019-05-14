#ifndef _DblSharpNote
#define _DblSharpNote

#include "AlteredNote.h"

class DblSharpNote : public AlteredNote
{

public:
    DblSharpNote(NaturalNote *);
    ~DblSharpNote(void);
    std::string display(void);
};

#endif
