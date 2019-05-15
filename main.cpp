#include "Note.h"
#include "Interval.h"

int main(int argc, char *argv[])
{
    Note::initialize();
    try
    {
        std::cout << Ab->semiToneCount() << std::endl;
        std::cout << Abb->semiToneCount() << std::endl;
        std::cout << G->semiToneCount() << std::endl;
        std::cout << As->semiToneCount() << std::endl;
        std::cout << Eb->semiToneCount() << std::endl;
        std::cout << Bs->semiToneCount() << std::endl;
        std::cout << F->semiToneCount() << std::endl;
        Interval inter1(2, 3);
        Interval inter3(7, 10);
        Interval inter4(5, 6);
        Interval inter5(4, 6);
        std::cout << inter1.show() << std::endl;
        std::cout << inter3.show() << std::endl;
        std::cout << inter4.show() << std::endl;
        std::cout << inter5.show() << std::endl;

    }
    catch (H_ERR err)
    {
        std::cout<<"ERROR: "<<handle_H_ERR(err)<<std::endl;
    }
}