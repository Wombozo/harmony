#include "Note.h"
#include "Interval.h"
#include <vector>

class Scale
{
private:
    std::vector<Interval> intervals;

protected:
    Note *tonic;
    std::string name;
    std::vector<Note*> notes;
    std::vector<int> degrees;

private:
    void setNotes(void);
public:
    Scale(Note *, const std::string &name);
    ~Scale();
    std::string display(void);
};