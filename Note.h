#ifndef _Note
#define _Note

#include <iostream>
#include <string>
#include "errors.h"

class NaturalNote;
class Note;

extern Note *A, *B, *C, *D, *E, *F, *G;
extern Note *Ab, *Bb, *Cb, *Db, *Eb, *Fb, *Gb;
extern Note *As, *Bs, *Cs, *Ds, *Es, *Fs, *Gs;
extern Note *Abb, *Bbb, *Cbb, *Dbb, *Ebb, *Fbb, *Gbb;
extern Note *Ass, *Bss, *Css, *Dss, *Ess, *Fss, *Gss;

class Note
{
public:
    static void initialize(void);
    virtual std::string display(void) = 0;
    virtual int semiToneShift(void) = 0;
    virtual NaturalNote *getNatural(void) = 0;
    virtual int getNextSTNatural(void) { return 0; }
};

#endif
