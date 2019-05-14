#ifndef _Note
#define _Note

#include <iostream>
#include <string>

class DblSharpNote;
class DblFlatNote;
class SharpNote;
class FlatNote;
class NaturalNote;

class Note
{
public:
    virtual void initialize(void) {}
};

#endif
