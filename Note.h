#ifndef _Note
#define _Note

#include <iostream>
#include <string>
#include "errors.h"

class Note
{
public:
    virtual std::string display(void) = 0;
    virtual int semiToneCount(void) = 0;
    static void initialize(void);
};

extern Note *A, *B, *C, *D, *E, *F, *G;
extern Note *Ab, *Bb, *Cb, *Db, *Eb, *Fb, *Gb;
extern Note *As, *Bs, *Cs, *Ds, *Es, *Fs, *Gs;
extern Note *Abb, *Bbb, *Cbb, *Dbb, *Ebb, *Fbb, *Gbb;
extern Note *Ass, *Bss, *Css, *Dss, *Ess, *Fss, *Gss;

#endif
