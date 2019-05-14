#ifndef _Note
#define _Note

#include <iostream>
#include <string>

class Note
{
public:
    virtual std::string display(void) = 0;
    virtual int semiToneCount(void) = 0;
};

#endif
