#include "Note.h"
#include "Chord.h"

int main(int argc, char *argv[])
{
    Note::initialize();
    try
    {
    }
    catch (H_ERR err)
    {
        std::cout << "ERROR: " << handle_H_ERR(err) << std::endl;
    }
}
