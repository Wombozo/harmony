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
    default:
        str = "Unknown error";
        break;
    }
    return str;
}
