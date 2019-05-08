#include "scale.h"

Scale::Scale(char n, char a, std::string t) : Note(n,a)
{
    type = t;
}

Scale::~Scale()
{
}

std::string Scale::getType()
{
    return type;
}

std::vector<int> getIntervals()
{
}

void Scale::setIntervals(std::vector<int> v)
{
    if (!type.compare("Major"))
    {
        std::cout << "Major scale" << std::endl;
        v = {2, 2, 1, 2, 2, 2, 1};
    }
}

void Scale::display()
{
    std::string s;
    for (auto &degree : degrees)
    {
        s+degree.display()+" ";
    }
    std::cout << s << std::endl;
}

std::vector<Note> Scale::getDegrees()
{
    return degrees;
}
