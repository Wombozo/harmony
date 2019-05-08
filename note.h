#include <iostream>
#include <string>

class Note
{
    protected:
        char name;
        char alt;
        static const char notes[] = {'A','B','C','D','E','F','G'}

    public:
           Note(char n, char a);
           ~Note();

           char getName(void);
           char getAlt(void);
           std::string display(void);

};

