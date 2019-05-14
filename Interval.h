#include "Note.h"

class Interval
{
private:
    int type;
    int semitones;
public:
    Interval(int, int);
    ~Interval(void);

    void computeInterval(Note*, Note*);

};