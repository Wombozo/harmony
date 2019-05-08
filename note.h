#ifndef NOTE
#define NOTE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Note
{
    protected:
        char name;
        char alt;

    public:
           Note(char n, char a);
           ~Note();

           char getName(void);
           char getAlt(void);
           std::string display(void);

};

std::vector<char> arrangeBaseNotes(char note);
#endif
