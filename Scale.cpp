#include "Scale.h"
#include "NaturalNote.h"
#include "SharpNote.h"
#include "FlatNote.h"
#include "SharpNote.h"

Scale::Scale(Note *t, const std::string &n) : tonic(t),name(n)
{
    if (n.compare("Major"))
    {
        //Interval t_int[6] = {Interval("major second"),
        intervals = {Interval("major second"),
                     Interval("major third"),
                     Interval("perfect fourth"),
                     Interval("perfect fifth"),
                     Interval("Major sixth"),
                     Interval("Major seventh")};
        tonic->getNatural()->sort();
        notes.push_back(tonic);
        NaturalNote *ntmp;
        SharpNote *stmp;
        FlatNote *ftmp;
        DblSharpNote *sstmp;
        DblFlatNote *fftmp;
        for (int i = 0; i < sizeof(intervals); i++)
        {
            
        }
    }
    else
        throw E_SCALE_UNKNOWN;
}