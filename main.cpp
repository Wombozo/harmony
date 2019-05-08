#include <iostream>
#include <string>
#include "scale.h"
#include "chord.h"

void init_chord(void)
{
    char baseNote, alt;
    bool valid_chord = false; 
    std::string quality;
    std::cout << "Tell me which chord you want starting from root." << std::endl;
    do
    {
        std::cout << "What root do you want ( A to G in upper case) : ";
        std::cin >> baseNote;
    } while (baseNote < 65 || baseNote > 71);
    std::cout << "Nice one. Now tell me the alteration." << std::endl;
    do
    {
        std::cout << "enter b, # or n for 'natural' : ";
        std::cin >> alt;
    } while (alt != 35 && alt != 98 && alt != 110);
    std::cout << "GOOOOD ! Hardest part now. Enter which chord you wanna see" << std::endl;
    do
    {
        std::cout << "Enter one of these : " << Chord::valid_chords() << " : "; 
        std::cin >> quality;
        valid_chord = checkName(quality);
    } while (valid_chord == false);
    Chord c(baseNote, alt, quality);
    //c.display();
    
}

void init_key(void)
{
    char baseNote, alt, type;
    do
    {
        std::cout << "Tell me which base note you want from A to G (in upper case) : ";
        std::cin >> baseNote;
    } while (baseNote < 65 || baseNote > 71);
    std::cout << "Goooood ! Now tell me the alteration." << std::endl;
    do
    {
        std::cout << "enter b, # or n for 'natural' : ";
        std::cin >> alt;
    } while (alt != 35 && alt != 98 && alt != 110);
    std::cout << "Good ! Here is your scale. But wait... Natural minor or Major ?" << std::endl;
    do
    {
        std::cout << "Enter M or m : ";
        std::cin >> type;

    } while (type != 109 && type != 77);
    Scale s(baseNote, (alt == 'n') ? ' ' : alt, (type == 77) ? "Major" : "Minor");
    s.display();

}

void help(void)
{
 std::cout << "If you want to find out notes of a key, press 'k'" << std::endl;
 std::cout << "If you want to find out notes of a chord, press 'c'" << std::endl;
}

int main(int argc, char *argv[])
{
 	std::cout << "Welcome to the harmony software. Here are the features : Keys, chords" << std::endl;
	char response;
	do
	{
		help();
		std::cin >> response ;
    }while (response != 'k' && response != 'c'); 
	switch(response)
    {
        case 'k':
            init_key();
            break;
        case 'c':
            init_chord();
            break;
        default:
            break;
    }
    return 0;
}
