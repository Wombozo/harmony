//#include "user.h"
#include "Chord.h"
#include <sstream>

int main(int argc, char *argv[])
{
    Note::initialize();
    try
    {
        std::cout << "// WELCOME TO HARMONY ANALYSER \\" << std::endl;
        std::cout << "This software has many features and will be improved by time. "
                     "Please use 'git pull' each time you want to use it to keep you updated."
                  << std::endl;
        Chord c(Ab,"7", 3);
        std::cout<< c.getName() << " : " << c.displayNotes() << std::endl;
    }
    catch (H_ERR err)
    {
        std::cout << "ERROR: " << handle_H_ERR(err) << std::endl;
    }
}