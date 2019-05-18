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
std::vector<Note *> Notes; 


void Note::initialize()
{
    NaturalNote *rA = new NaturalNote("A", "La", 2);
    DblFlatNote *rabb = new DblFlatNote(rA);
    FlatNote *rab = new FlatNote(rA, rabb);
    DblSharpNote *rass = new DblSharpNote(rA);
    SharpNote *ras = new SharpNote(rA, rass);

    NaturalNote *rB = new NaturalNote("B", "Si", 1);
    DblFlatNote *rbbb = new DblFlatNote(rB);
    FlatNote *rbb = new FlatNote(rB, rbbb);
    DblSharpNote *rbss = new DblSharpNote(rB);
    SharpNote *rbs = new SharpNote(rB, rbss);

    NaturalNote *rC = new NaturalNote("C", "Do", 2);
    DblFlatNote *rcbb = new DblFlatNote(rC);
    FlatNote *rcb = new FlatNote(rC, rcbb);
    DblSharpNote *rcss = new DblSharpNote(rC);
    SharpNote *rcs = new SharpNote(rC, rcss);

    NaturalNote *rD = new NaturalNote("D", "Ré", 2);
    DblFlatNote *rdbb = new DblFlatNote(rD);
    FlatNote *rdb = new FlatNote(rD, rdbb);
    DblSharpNote *rdss = new DblSharpNote(rD);
    SharpNote *rds = new SharpNote(rD, rdss);

    NaturalNote *rE = new NaturalNote("E", "Mi", 1);
    DblFlatNote *rebb = new DblFlatNote(rE);
    FlatNote *reb = new FlatNote(rE, rebb);
    DblSharpNote *ress = new DblSharpNote(rE);
    SharpNote *res = new SharpNote(rE, ress);

    NaturalNote *rF = new NaturalNote("F", "Fa", 2);
    DblFlatNote *rfbb = new DblFlatNote(rF);
    FlatNote *rfb = new FlatNote(rF, rfbb);
    DblSharpNote *rfss = new DblSharpNote(rF);
    SharpNote *rfs = new SharpNote(rF, rfss);

    NaturalNote *rG = new NaturalNote("G", "Sol", 2);
    DblFlatNote *rgbb = new DblFlatNote(rG);
    FlatNote *rgb = new FlatNote(rG, rgbb);
    DblSharpNote *rgss = new DblSharpNote(rG);
    SharpNote *rgs = new SharpNote(rG, rgss);

    rA->next = rB;
    rB->next = rC;
    rC->next = rD;
    rD->next = rE;
    rE->next = rF;
    rF->next = rG;
    rG->next = rA;

    rA->previous = rG;
    rB->previous = rA;
    rC->previous = rB;
    rD->previous = rC;
    rE->previous = rD;
    rF->previous = rE;
    rG->previous = rF;

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

    Ass = (Note *)rass;
    Bss = (Note *)rass;
    Css = (Note *)rass;
    Dss = (Note *)rass;
    Ess = (Note *)rass;
    Fss = (Note *)rass;
    Gss = (Note *)rass;

    Abb = (Note *)rabb;
    Bbb = (Note *)rbbb;
    Cbb = (Note *)rcbb;
    Dbb = (Note *)rdbb;
    Ebb = (Note *)rebb;
    Fbb = (Note *)rfbb;
    Gbb = (Note *)rgbb;

    As = (Note *)ras;
    Bs = (Note *)rbs;
    Cs = (Note *)rcs;
    Ds = (Note *)rds;
    Es = (Note *)res;
    Fs = (Note *)rfs;
    Gs = (Note *)rgs;

    Ab = (Note *)rab;
    Bb = (Note *)rbb;
    Cb = (Note *)rcb;
    Db = (Note *)rdb;
    Eb = (Note *)reb;
    Fb = (Note *)rfb;
    Gb = (Note *)rgb;

    A = (Note *)rA;
    B = (Note *)rB;
    C = (Note *)rC;
    D = (Note *)rD;
    E = (Note *)rE;
    F = (Note *)rF;
    G = (Note *)rG;
    Notes = {A, B, C, D, E, F, G, Ab, Bb, Cb, Db, Eb, Fb, Gb, As, Bs, Cs, Ds, Es, Fs, Gs, Abb, Bbb, Cbb, Dbb, Ebb, Fbb, Gbb, Ass, Bss, Css, Dss, Ess, Fss, Gss};
}
