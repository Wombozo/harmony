#include "Note.h"

class Interval
{
private:
    std::string name;
    int type;
    int semitones;

public:
    Interval(std::string str);
    ~Interval(void);
    std::string getName(void);
    int getType(void);
    int getSemiTones(void);
    Note* getNext(Note*);
    Note* getNextSorted(Note*);
};