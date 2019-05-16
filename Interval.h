#include "Note.h"

class Interval
{
private:
    int type;
    int semitones;
    std::string name;

public:
    Interval(std::string str);
    ~Interval(void);
    std::string getName(void);
    int getType(void);
    int getSemiTones(void);
};