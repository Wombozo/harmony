#include "errors.h"

std::string handle_H_ERR(H_ERR e)
{
    std::string str;
    switch (e)
    {
    case E_INTERVAL:
        str = "Invalid interval";
        break;
    case E_CHORD_UNKNOWN:
        str = "Unknown chord";
        break;
    case E_INVERSION:
        str = "Cannot invert chord";
        break;
    case E_SCALE_UNKNOWN:
        str = "Unknown scale";
        break;
    case E_CHOICE:
        str = "Bad choice";
    case E_DEGREE_NOT_FOUND:
        str = "Degree not found";
    default:
        str = "Unknown error";
        break;
    }
    return str;
}
