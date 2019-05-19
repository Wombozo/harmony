#ifndef _ERRORS
#define _ERRORS

#include <string>

typedef enum
{
    E_INTERVAL,
    E_CHORD_UNKNOWN,
    E_INVERSION,
    E_SCALE_UNKNOWN,
    E_CHOICE,
    E_DEGREE_NOT_FOUND,
} H_ERR;

std::string handle_H_ERR(H_ERR e);

#endif
