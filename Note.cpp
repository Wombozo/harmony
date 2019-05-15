#include "Note.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

Note *A, *B, *C, *D, *E, *F, *G;
Note *Ab, *Bb, *Cb, *Db, *Eb, *Fb, *Gb;
Note *As, *Bs, *Cs, *Ds, *Es, *Fs, *Gs;
Note *Abb, *Bbb, *Cbb, *Dbb, *Ebb, *Fbb, *Gbb;
Note *Ass, *Bss, *Css, *Dss, *Ess, *Fss, *Gss;

void Note::initialize()
{
       NaturalNote *rA = new NaturalNote("A", "La", 0);
    DblFlatNote *rabb = new DblFlatNote(rA);
    FlatNote *rab = new FlatNote(rA,rabb);
    DblSharpNote *rass = new DblSharpNote(rA);
    SharpNote *ras = new SharpNote(rA, rass);

    NaturalNote *rB = new NaturalNote("B", "Si", 2);
    DblFlatNote *rbbb = new DblFlatNote(rB);
    FlatNote *rbb = new FlatNote(rB,rbbb);
    DblSharpNote *rbss = new DblSharpNote(rB);
    SharpNote *rbs = new SharpNote(rB, rbss);

    NaturalNote *rC = new NaturalNote("C", "Do", 3);
    DblFlatNote *rcbb = new DblFlatNote(rC);
    FlatNote *rcb = new FlatNote(rC,rcbb);
    DblSharpNote *rcss = new DblSharpNote(rC);
    SharpNote *rcs = new SharpNote(rC, rcss);

    NaturalNote *rD = new NaturalNote("D", "Ré", 5);
    DblFlatNote *rdbb = new DblFlatNote(rD);
    FlatNote *rdb = new FlatNote(rD,rdbb);
    DblSharpNote *rdss = new DblSharpNote(rD);
    SharpNote *rds = new SharpNote(rA, rdss);

    NaturalNote *rE = new NaturalNote("C", "Mi", 7);
    DblFlatNote *rebb = new DblFlatNote(rE);
    FlatNote *reb = new FlatNote(rE,rebb);
    DblSharpNote *ress = new DblSharpNote(rE);
    SharpNote *res = new SharpNote(rE, ress);

    NaturalNote *rF = new NaturalNote("F", "Fa", 8);
    DblFlatNote *rfbb = new DblFlatNote(rF);
    FlatNote *rfb = new FlatNote(rF,rfbb);
    DblSharpNote *rfss = new DblSharpNote(rF);
    SharpNote *rfs = new SharpNote(rF, rfss);

    NaturalNote *rG = new NaturalNote("G", "Sol", 10);
    DblFlatNote *rgbb = new DblFlatNote(rG);
    FlatNote *rgb = new FlatNote(rG,rgbb);
    DblSharpNote *rgss = new DblSharpNote(rG);
    SharpNote *rgs = new SharpNote(rG, rgss);

    rA->following = rB;
    rB->following = rC;
    rC->following = rD;
    rD->following = rE;
    rE->following = rF;
    rF->following = rG;
    rG->following = rA;

    rA->preceding = rG;
    rB->preceding = rA;
    rC->preceding = rB;
    rD->preceding = rC;
    rE->preceding = rD;
    rF->preceding = rE;
    rG->preceding = rF;

    rA->sn = ras;
    rB->sn = rbs;
    rC->sn = rcs;
    rD->sn = rds;
    rE->sn = res;
    rF->sn = rfs;
    rG->sn = rgs;

    rA->fn = rab;
    rB->fn = rbb;
    rC->fn = rcb;
    rD->fn = rdb;
    rE->fn = reb;
    rF->fn = rfb;
    rG->fn = rgb;

    Ass = (Note*) rass;
    Bss = (Note*) rass;
    Css = (Note*) rass;
    Dss = (Note*) rass;
    Ess = (Note*) rass;
    Fss = (Note*) rass;
    Gss = (Note*) rass;

    Abb = (Note*) rabb;
    Bbb = (Note*) rbbb;
    Cbb = (Note*) rcbb;
    Dbb = (Note*) rdbb;
    Ebb = (Note*) rebb;
    Fbb = (Note*) rfbb;
    Gbb = (Note*) rgbb;

    As = (Note*) ras;
    Bs = (Note*) rbs;
    Cs = (Note*) rcs;
    Ds = (Note*) rds;
    Es = (Note*) res;
    Fs = (Note*) rfs;
    Gs = (Note*) rgs;

    Ab = (Note*) rab;
    Bb = (Note*) rab;
    Cb = (Note*) rab;
    Db = (Note*) rab;
    Eb = (Note*) rab;
    Fb = (Note*) rab;
    Gb = (Note*) rab;

    A = (Note*) rA;
    B = (Note*) rB;
    C = (Note*) rC;
    D = (Note*) rD;
    E = (Note*) rE;
    F = (Note*) rF;
    G = (Note*) rG;
}