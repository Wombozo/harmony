#include <string>
#include <vector>
#include <iostream>
#include "note.h"

class Scale : public Note
{
    private:
        std::string type;
        std::vector<Note> degrees;
        std::vector<int> intervals;
        int nb;


    public:
        Scale(char n, char a, std::string t);
        ~Scale();
        
        std::string getType(void);
  
        std::vector<Note> getDegrees(void);
        std::vector<int> getIntervals(void);
        void setIntervals(std::vector<int>);
        void display(void);
};
