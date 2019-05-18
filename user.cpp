#include "user.h"

static void handle_cd()
{
    std::string root, type;
    do
    {
        std::cin.clear();
        std::cout << "Select the root note of the chord you want to display : ";
        std::cin >> root;
    } while (!valid_user_note_input(root));
    do
    {
        std::cin.clear();
        std::cout << "Select the type chord you want : ";
        std::cin >> type;
    } while (!valid_user_type_chord_input(type));
    Note *tmp = u_parse_note(root);
    if (!type.compare("M"))
        type = "";
    Chord c(tmp, type);
    std::cout << c.getName() << " : " << c.displayNotes() << std::endl;
}

static void handle_sd()
{
    std::string tonic, scale;
        do
        {
            std::cin.clear();
            std::cout << "Select the tonic : ";
            std::cin >> tonic;
        } while (!valid_user_note_input(tonic));
        do
        {
            std::cin.clear();
            std::cout << "Select the scale : ";
            std::cin >> std::ws;
            std::getline(std::cin, scale);
        } while (!valid_user_type_scale_input(scale));
        Note *tmp = u_parse_note(tonic);
        Scale s(tmp,scale);
        std::cout << tmp->display() + " scale is : " + s.display() <<std::endl;
}

static void handle_id()
{
    std::string root, sint;
    do
    {
        std::cin.clear();
        std::cout << "Select the first note of the interval : ";
        std::cin >> root;
    } while (!valid_user_note_input(root));
    do
    {
        std::cin.clear();
        std::cout << "Select the interval : ";
        std::cin >> std::ws;
        std::getline(std::cin, sint);
    } while (!valid_user_type_interval_input(sint));
    Note *tmp = u_parse_note(root);
    Interval i(sint);
    std::cout << "The " + sint + " above " << tmp->display() << " is " << i.getNext(tmp)->display() << std::endl;
}

void handle_choice(int c)
{
    switch (c)
    {
    case C_CD:
        handle_cd();
        break;
    case C_SD:
        handle_sd();
        break;
    case C_ID:
        handle_id();
        break;
    default:
        throw E_CHOICE;
    }
}

void interact()
{
    std::cout << std::endl;
    int choice;
    do
    {
        std::cout << "Select which feature you want to use (ex : 2) or '-1' to see features : " << std::endl;
        std::cin >> choice;
        if (choice == -1)
            help();
    } while (!std::cin || choice > 3 || choice < 0);
    handle_choice(choice);
}

void help()
{
    std::cout << "Features : " << std::endl;
    std::cout << "\t -> Chord display (" << C_CD << ")" << std::endl;
    std::cout << "\t -> Scale display (" << C_SD << ")" << std::endl;
    std::cout << "\t -> Interval display (" << C_ID << ")" << std::endl;
}
