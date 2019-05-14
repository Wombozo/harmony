#include "Chord.h"

Chord::Chord(Note *n, std::vector<std::tuple<int, int>> ints)
{
    root = n;
    nb = (int) ints.size() + 1;
    intervals;
    intervals.clear();
    for (int i =0; i < ints.size(); i++)
    {
        Interval itinter(std::get<0>(ints[i]), std::get<1>(ints[i]));
        intervals.push_back(itinter);
    }

}

Chord::~Chord()
{

}
