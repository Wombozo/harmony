#ifndef _FlatNote
#define _FlatNote

#include "AlteredNote.h"

class DblFlatNote;

class FlatNote: public AlteredNote
{
       private:
           DblFlatNote *flat;
        public:
           FlatNote(DblFlatNote *flat);
           ~FlatNote(void);
           void initialize(void);

};

#endif
