#include "Note.h"
#include "Interval.h"
#include <vector>
#include "Chord.h"

class Scale
{
private:
    std::vector<Interval> intervals;

protected:
    Note *tonic;
    std::string name;
    std::vector<Note *> notes;

public:
    std::vector<Chord> degChords;

private:
    void setNotes(void);

public:
    Scale(Note *, const std::string &name);
    ~Scale();
    std::string display(void);
    int getDegree(Note *);
    Note *getDegree(int);
    template <typename T>
    Chord getDegreeChord(T);
};