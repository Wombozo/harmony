#include "Note.h"
#include "Chord.h"

int main(int argc, char *argv[])
{
    Note::initialize();
    try
    {
        Chord c1(B, "major");
        std::cout<<c1.displayNotes()<<std::endl;
        Chord c2(C, "major");
        std::cout<<c2.displayNotes()<<std::endl;
        Chord c3(F, "major");
        std::cout<<c3.displayNotes()<<std::endl;
        Chord c4(A, "major");
        std::cout<<c4.displayNotes()<<std::endl;
        Chord c5(E, "major");
        std::cout<<c5.displayNotes()<<std::endl;
        Chord c6(C, "augmented");
        std::cout<<c6.displayNotes()<<std::endl;
        Chord c7(G, "7");
        std::cout<<c7.displayNotes()<<std::endl;
        Chord c8(E, "Fr6");
        std::cout<<c8.displayNotes()<<std::endl;
        Chord c9(C, "dim7");
        std::cout<<c9.displayNotes()<<std::endl;
    }
    catch (H_ERR err)
    {
        std::cout<<"ERROR: "<<handle_H_ERR(err)<<std::endl;
    }
}
