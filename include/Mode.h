#include "Scale.h"

class Mode: public Scale
{
    public:
    std::string name;

    public:
    Mode(Note *t, const std::string&);
    ~Mode();

};