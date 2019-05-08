#include <iostream>
#include <string>
#include "scale.h"

int main(int argc, char *argv[])
{
    Note a('A','#'),b('B',(char) 0);

    std::cout << "Note " << a.display() << std::endl;
    std::cout << "Note " << b.display() << std::endl;

    return 0;
}
