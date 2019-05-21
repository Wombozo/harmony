#include "Chord.h"
#include "Interval.h"
#include "NaturalNote.h"
#include "DblFlatNote.h"
#include "DblSharpNote.h"
#include "SharpNote.h"
#include "FlatNote.h"

#define CHORD_COUNT 10

const std::string chords[CHORD_COUNT] = {"7", "maj7", "m7", "minmaj7", "7b5", "m7b5", "dim7", "6", "m6", "7sus4"};

Chord::Chord(Note *n, const std::string &str) : Chord(n, str, n, 0)
{
}

Chord::Chord(Note *n, const std::string &str, int inv) : Chord(n, str, n, inv)
{
}

Chord::Chord(Note *n, const std::string &str, Note *b) : Chord(n, str, b, 0)
{
}

static std::string getTriad(const std::string &str)
{
    std::string triad;
    if (!str.compare("7"))
    {
        triad = "";
    }
    return triad;
}

Chord::Chord(Note *n, const std::string &str, Note *b, int inv) : Triad(n, getTriad(str), b, inv)
{
    Note *tmp;
    Interval *interval;
    name = str;
    if (!str.compare(chords[0]))
    {
        // "7"
        interval = new Interval("minor seventh");
        tmp = interval->getNextSorted(n);
        notes.push_back(tmp);
        delete (interval);
    }
}

void Chord::setInversion()
{
    if (inversion > 3)
        throw E_INVERSION;
    std::rotate(notes.begin(), notes.begin() + inversion, notes.end());
}

Chord::~Chord()
{

}