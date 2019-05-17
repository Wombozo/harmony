#include "Note.h"
#include "Chord.h"

int main(int argc, char *argv[])
{
    Note::initialize();
    try
    {
        Chord c1(B, "major");
        Chord c2(C, "major");
        Chord c3(Gs, "major");
        Chord c4(Bb, "major");
        Chord c5(E, "major");
    }
    catch (H_ERR err)
    {
        std::cout<<"ERROR: "<<handle_H_ERR(err)<<std::endl;
    }
}
