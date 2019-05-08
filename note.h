#include <iostream>
#include <string>

class Note
{
    private:
        char name;
        char alt;

    public:
           Note(char n, char a);
           ~Note();

           char getName(void);
           char getAlt(void);
           std::string display(void);

};

