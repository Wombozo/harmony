#ifndef CHORD
#define CHORD

#include "note.h"
#include "utils.h"

#define NAME_IS(x) (#x == n)

int checkName(std::string n);

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
       void displayNameChord(void);
       void setNb(int n);
       void buildChord(void);

    private:
       void setNameChord(std::string quality);
       void buildChord3(std::string c);

};

#endif
