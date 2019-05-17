#include "Note.h"
#include "Chord.h"

int main(int argc, char *argv[])
{
    Note::initialize();
    try
    {
        Chord c1(Eb, "");
        std::cout << c1.displayNotes() << std::endl;
        Chord c2(Fs, "m");
        std::cout << c2.displayNotes() << std::endl;
        Chord c3(F, "7b5");
        std::cout << c3.displayNotes() << std::endl;
        Chord c4(Cbb, "m");
        std::cout << c4.displayNotes() << std::endl;
    }
    catch (H_ERR err)
    {
        std::cout << "ERROR: " << handle_H_ERR(err) << std::endl;
    }
}
