#ifndef _ERRORS
#define _ERRORS

#include <string>

typedef enum
{
    E_INTERVAL,
    E_CHORD_UNKNOWN
} H_ERR;

std::string handle_H_ERR(H_ERR e);

#endif
