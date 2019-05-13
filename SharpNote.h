#ifndef _SharpNote
#define _SharpNote

#include "AlteredNote.h"

class DblSharpNote;

class SharpNote:public AlteredNote
{
    private:
        DblSharpNote *flat;

    public:
        SharpNote(DblSharpNote *flat);
        ~SharpNote(void);
        void initialize(void);

};

#endif
