#ifndef _UTILS
#define _UTILS
#include "Note.h"

bool valid_user_note_input(const std::string&);
bool valid_user_type_chord_input(const std::string&);
bool valid_user_type_interval_input(const std::string&);
bool valid_user_type_scale_input(const std::string&);
Note  *u_parse_note(const std::string&);

#endif