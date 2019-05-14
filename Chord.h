#include "Note.h"
#include "Interval.h"
#include <vector>
#include <tuple>

class Chord
{
    private:
    Note *root;
    int nb;
    std::vector<Interval> intervals;    

    public:
    Chord(Note*, std::vector<std::tuple<int, int>>);
    ~Chord();
};