#include "user.h"
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

        Scale s(Ab, "Major");
        std::cout << s.getDegreeChord<int>(3).getName() << std::endl;
//        std::cout << s.getDegreeChord(C) << std::endl;
        //    if (argc == 2)
        //    {
        //        std::istringstream ss(argv[1]);
        //        int val;
        //        if (ss >> val)
        //            interact(val);
        //        else
        //        {
        //            help();
        //            interact(0);
        //        }
        //    }
        //    else
        //    {
        //           help();
        //           interact(0);
        //    }
    }
    catch (H_ERR err)
    {
        std::cout << "ERROR: " << handle_H_ERR(err) << std::endl;
    }
}