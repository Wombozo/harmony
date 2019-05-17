#include "Note.h"
#include "Interval.h"
#include <vector>

class Scale
{
public:
    Note *tonic;
    std::string name;
    std::vector<Interval> intervals;
    std::vector<Note*> notes;

public:
    Scale(Note *, const std::string &name);
    ~Scale();
};