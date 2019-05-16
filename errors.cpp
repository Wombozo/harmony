#include "errors.h"


std::string handle_H_ERR(H_ERR e)
{
    std::string str;
    switch (e)
    {
    case E_INTERVAL:
        str = "Invalid interval";
        break;
    case E_CHORD_LIMIT_SIZE:
        str = "Chord is too big";
        break;
    case E_CHORD_TOO_SMALL:
        str = "Chord is too small";
        break;
    case E_CHORD_UNKNOWN:
        str = "Unknown chord";
        break;
    default:
        str = "Unknown error";
        break;
    }
    return str;
}
