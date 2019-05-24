#include "utils.h"

static const std::vector<std::string> snotes({"A", "B", "C", "D", "E", "F", "G",
                                              "Ab", "Bb", "Cb", "Db", "Eb", "Fb", "Gb",
                                              "A#", "B#", "C#", "D#", "E#", "F#", "G#",
                                              "Abb", "Bbb", "Cbb", "Dbb", "Ebb", "Fbb", "Gbb",
                                              "A##", "B##", "C##", "D##", "E##", "F##", "G##"});

bool valid_user_note_input(const std::string &str)
{
    for (auto snote : snotes)
    {
        if (!snote.compare(str))
            return true;
    }
    std::cout << "Available answers : ";
    for (auto snote : snotes)
    {
        std::cout << "| " + snote + " | ";
    }
    std::cout << std::endl;
    return false;
}

bool valid_user_type_interval_input(const std::string &str)
{
    std::string sints[] = {"minor second",
                           "major second",
                           "augmented second",
                           "diminished third",
                           "minor third",
                           "major third",
                           "augmented third",
                           "diminished fourth",
                           "perfect fourth",
                           "augmented fourth",
                           "diminished fifth",
                           "perfect fifth",
                           "augmented fifth",
                           "diminished sixth",
                           "minor sixth",
                           "major sixth",
                           "augmented sixth",
                           "diminished seventh",
                           "minor seventh",
                           "major seventh"};
    for (auto sint : sints)
    {
        if (!sint.compare(str))
            return true;
    }
    std::cout << "Available answers : ";
    for (auto sint : sints)
    {
        std::cout << "| " + sint + " | ";
    }
    std::cout << std::endl;
    return false;
}
bool valid_user_type_scale_input(const std::string &str)
{
    std::string sscales[] = {"Major",
                             "Minor"};
    for (auto scale : sscales)
    {
        if (!scale.compare(str))
            return true;
    }
    std::cout << "Available answers : ";
    for (auto sscale : sscales)
    {
        std::cout << "| " + sscale + " | ";
    }
    std::cout << std::endl;
    return false;
}
bool valid_user_type_chord_input(const std::string &str)
{
    std::string stypes[] = {"M",
                            "m",
                            "dim",
                            "aug",
                            "sus4",
                            "7sus4",
                            "sus2",
                            "m7",
                            "7",
                            "maj7",
                            "minmaj7",
                            "6",
                            "m6",
                            "7b5",
                            "dim7",
                            "m7b5"};
    for (auto stype : stypes)
    {
        if (!stype.compare(str))
            return true;
    }
    std::cout << "Available answers : ";
    for (auto stype : stypes)
    {
        std::cout << "| " + stype + " | ";
    }
    std::cout << std::endl;
    return false;
}

Note *u_parse_note(const std::string &str)
{
    Note *tmp;
    for (int i = 0; i < snotes.size(); i++)
    {
        if (!str.compare(snotes.at(i)))
        {
            tmp = Notes.at(i);
        }
    }
    return tmp;
}