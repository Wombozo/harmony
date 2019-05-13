#ifndef _Note
#define _Note

#include <iostream>
#include <string>

class Note {
    public:
    void initialize(void){

    Note *ass = new DblSharpNote();
    Note *bss = new DblSharpNote();
    Note *css = new DblSharpNote();
    Note *dss = new DblSharpNote();
    Note *ess = new DblSharpNote();
    Note *fss = new DblSharpNote();
    Note *gss = new DblSharpNote();

    Note *abb = new DblFlatNote();
    Note *bbb = new DblFlatNote();
    Note *cbb = new DblFlatNote();
    Note *dbb = new DblFlatNote();
    Note *ebb = new DblFlatNote();
    Note *fbb = new DblFlatNote();
    Note *gbb = new DblFlatNote();

    Note *as = new SharpNote((DblSharpNote*) ass);
    Note *bs = new SharpNote((DblSharpNote*) bss);
    Note *cs = new SharpNote((DblSharpNote*) css);
    Note *ds = new SharpNote((DblSharpNote*) dss);
    Note *es = new SharpNote((DblSharpNote*) ess);
    Note *fs = new SharpNote((DblSharpNote*) fss);
    Note *gs = new SharpNote((DblSharpNote*) gss);

    Note *ab = new FlatNote((DblFlatNote*) abb);
    Note *bb = new FlatNote((DblFlatNote*) bbb);
    Note *cb = new FlatNote((DblFlatNote*) cbb);
    Note *db = new FlatNote((DblFlatNote*) dbb);
    Note *eb = new FlatNote((DblFlatNote*) ebb);
    Note *fb = new FlatNote((DblFlatNote*) fbb);
    Note *gb = new FlatNote((DblFlatNote*) gbb);
    
    Note *A = new NaturalNote("A","La",1);
    Note *B = new NaturalNote("B","Si",3);
    Note *C = new NaturalNote("C","Do",4);
    Note *D = new NaturalNote("D","Ré",6);
    Note *E = new NaturalNote("E","Mi",8);
    Note *F = new NaturalNote("F","Fa",9);
    Note *G = new NaturalNote("G","Sol",11);
    }
};

#endif
