#ifndef CHORD
#define CHORD

#include "note.h"
#include <string.h>


#define NAME_IS(x) (#x == n)

bool checkName(std::string n);

class Chord : public Note
{
    private:
       std::vector<Note> notes;
       std::string nameChord;
       int nb;
       
    public:
       Chord(char root, char alt, std::string n);
       ~Chord();
       static const std::string valid_chords(void);
       void display(void);

    private:
       void setNameChord(void);

};

#endif
