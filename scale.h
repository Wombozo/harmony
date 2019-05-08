#ifndef SCALE
#define SCALE

#include <string>
#include <vector>
#include <iostream> 
#include <algorithm>

#include "utils.h"

#define SCALE_IS(x) (!type.compare(#x))

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
        void display(void);
        
    private:
        std::string getType(void);
        std::vector<Note> getDegrees(void);
        std::vector<int> getIntervals(void);

        void displayDegrees(void);
  
        void setIntervals(void);
        void setDegrees(void);
};
#endif
