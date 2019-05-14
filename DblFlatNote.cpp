#include "DblFlatNote.h"

DblFlatNote::DblFlatNote(NaturalNote *n)
{
    setNatural(n);
}

DblFlatNote::~DblFlatNote()
{
}
std::string DblFlatNote::display()
{

    return getNatural()->display()+"bb";

}