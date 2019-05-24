#ifndef _INTERVAL
#define _INTERVAL

#include "Note.h"

class Interval
{
private:
    std::string name;
    int type;
    int semitones;

public:
    Interval(const std::string &str);
    Interval(int, int);
    ~Interval(void);
    std::string getName(void);
    int getType(void);
    int getSemiTones(void);
    Note* getNext(Note*);
    Note* getNextSorted(Note*);
};

#endif
