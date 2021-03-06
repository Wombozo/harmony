#include "user.h"

int main(int argc, char *argv[])
{
    Note::initialize();
    try
    {
        std::cout << "// WELCOME TO HARMONY ANALYSER \\" << std::endl;
        std::cout << "This software has many features and will be improved by time. "
                     "Please use 'git pull' each time you want to use it to keep you updated."
                  << std::endl;
        if (argc > 1)
            interact(atoi(argv[1]));
        else
        {
            help();
            interact(0);
        }
    }
    catch (H_ERR err)
    {
        std::cout << "ERROR: " << handle_H_ERR(err) << std::endl;
    }
}
