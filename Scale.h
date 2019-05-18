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

private:
    void setNotes(void);
public:
    Scale(Note *, const std::string &name);
    ~Scale();
    std::string display(void);
};