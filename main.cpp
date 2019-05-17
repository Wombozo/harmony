#include "Note.h"
#include "Chord.h"

int main(int argc, char *argv[])
{
    Note::initialize();
    try
    {
       // Chord c(Cs, "m7b5");
       // std::cout<<"Chord " << c.getName() << " : " << c.displayNotes()<<std::endl;
       // Chord cb(C,"m",G);
       // std::cout<<"Chord " << cb.getName() << " : " << cb.displayNotes()<<std::endl;
       // Chord ci(Ab,"m7",2);
       // std::cout<<"Chord " << ci.getName() << " : " << ci.displayNotes()<<std::endl;
        Chord ce(A,"m",2);
        std::cout<<"Chord " << ce.getName() << " : " << ce.displayNotes()<<std::endl;
    }
    catch (H_ERR err)
    {
        std::cout << "ERROR: " << handle_H_ERR(err) << std::endl;
    }
}
