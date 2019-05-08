#include "scale.h"

Scale::Scale(char n, char a, std::string t) : Note(n,a)
{
    type.assign(t);
    setIntervals();
}

Scale::~Scale()
{
}

std::string Scale::getType()
{
    return type;
}

std::vector<int> Scale::getIntervals()
{
    return intervals;
}

void Scale::setDegrees()
{

}

void Scale::setIntervals()
{
    if SCALE_IS(Major)
    {
        intervals = {2, 2, 1, 2, 2, 2, 1};
    }
}

void Scale::display()
{
    std::cout << name << alt << " " << type << " scale" << std::endl;
}

void Scale::displayDegrees()
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
