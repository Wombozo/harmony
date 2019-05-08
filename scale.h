#include <string>
#include <vector>
#include <iostream>
#include "note.h"

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
        
        std::string getType(void);
        std::vector<Note> getDegrees(void);
        std::vector<int> getIntervals(void);

        void display(void);
        void displayDegrees(void);
  
        void setIntervals(void);
        void setDegrees(void);
};
