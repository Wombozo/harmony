#include "Note.h"
#include "Chord.h"

int main(int argc, char *argv[])
{
    Note::initialize();
    try
    {
    //    Chord c1(C, "minor");
    //    Chord c2(A, "major");
        Chord c3(A, "Ger6");
        std::cout<< A->gS() << " " << B->gS() << " " << C->gS() << " " << D->gS() << " " << E->gS() <<std::endl;
//        E->rotateST();
    //    std::cout<<" NEXT " <<std::endl;
    //    Chord c4(A, "7");
    //    Chord c5(F, "major");
    //    Chord c6(G, "augmented");
    }
    catch (H_ERR err)
    {
        std::cout<<"ERROR: "<<handle_H_ERR(err)<<std::endl;
    }
}
