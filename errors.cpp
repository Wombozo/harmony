#include "errors.h"

std::string handle_H_ERR(H_ERR e)
{
    std::string str;
    switch (e)
    {
    case E_INTERVAL:
        str = "Invalid interval";
        break;
    default:
        str = "Unknown error";
        break;
    }
    return str;
}