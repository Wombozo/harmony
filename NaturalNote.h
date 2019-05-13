#ifndef _NaturalNote
#define _NaturalNote

#include "Note.h"

class SharpNote;
class FlatNote;

class NaturalNote: public virtual Note {

    private:
        std::string name;
        std::string fname;
        SharpNote *sn;
        FlatNote *fn;
        int semiToneCount;
    public:
        NaturalNote *following;
        NaturalNote *preceding;

    public:
        NaturalNote(std::string, std::string, int);
        ~NaturalNote();
        std::string getName(void);
        std::string getFName(void);
        SharpNote* getSharpNote(void);
        FlatNote* getFlatNote(void);
        int getSemiToneCount(void);


};

#endif
