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

    Ass = static_cast<Note*>(rass);
    Bss = static_cast<Note*>(rbss);
    Css = static_cast<Note*>(rcss);
    Dss = static_cast<Note*>(rdss);
    Ess = static_cast<Note*>(ress);
    Fss = static_cast<Note*>(rfss);
    Gss = static_cast<Note*>(rgss);

    Abb = static_cast<Note*>(rabb);
    Bbb = static_cast<Note*>(rbbb);
    Cbb = static_cast<Note*>(rcbb);
    Dbb = static_cast<Note*>(rdbb);
    Ebb = static_cast<Note*>(rebb);
    Fbb = static_cast<Note*>(rfbb);
    Gbb = static_cast<Note*>(rgbb);

    As = static_cast<Note*>(ras);
    Bs = static_cast<Note*>(rbs);
    Cs = static_cast<Note*>(rcs);
    Ds = static_cast<Note*>(rds);
    Es = static_cast<Note*>(res);
    Fs = static_cast<Note*>(rfs);
    Gs = static_cast<Note*>(rgs);

    Ab = static_cast<Note*>(rab);
    Bb = static_cast<Note*>(rbb);
    Cb = static_cast<Note*>(rcb);
    Db = static_cast<Note*>(rdb);
    Eb = static_cast<Note*>(reb);
    Fb = static_cast<Note*>(rfb);
    Gb = static_cast<Note*>(rgb);

    A = static_cast<Note*>(rA);
    B = static_cast<Note*>(rB);
    C = static_cast<Note*>(rC);
    D = static_cast<Note*>(rD);
    E = static_cast<Note*>(rE);
    F = static_cast<Note*>(rF);
    G = static_cast<Note*>(rG);
    Notes = {A, B, C, D, E, F, G, Ab, Bb, Cb, Db, Eb, Fb, Gb, As, Bs, Cs, Ds, Es, Fs, Gs, Abb, Bbb, Cbb, Dbb, Ebb, Fbb, Gbb, Ass, Bss, Css, Dss, Ess, Fss, Gss};
}
