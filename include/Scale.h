#include "Note.h"
#include "Interval.h"
#include <vector>

class Scale
{
private:
    std::vector<Interval> intervals;

protected:
    Note *tonic;
    std::string name;
    std::vector<Note*> notes;

private:
    void setNotes(void);
public:
    Scale(Note *, const std::string &name);
    ~Scale();
    std::string display(void);
    int getDegree(Note*);
    Note* getDegree(int);
};