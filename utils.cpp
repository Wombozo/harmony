#include "utils.h"

char alterate(int interval, Note prev)
{
    char ret = (char) 0;
	if (interval == 2)
	{
        switch (prev.getName())
        {
            case 'A':
                if (prev.getAlt() == '#')
                    ret = ' ';
                else
                    ret = prev.getAlt();
                break;
            case 'B':
                if (prev.getAlt() == 'b')
                    ret = ' ';
                else
                    ret = '#';
                break;
            case 'C':
                ret = prev.getAlt();
                break;
            case 'D':
                ret = prev.getAlt();
                break;
            case 'E':
                if (prev.getAlt() == 'b')
                    ret = ' ';
                else
                    ret = '#';
                break;
            case 'F':
                ret = prev.getAlt();
                break;
            case 'G':
                ret = prev.getAlt();
                break;
            default:
                break;
        }
	}	
    else if (interval == 1)
    {
        switch (prev.getName())
        {
            case 'A':
                if (prev.getAlt() == ' ')
                    ret = 'b';
                else
                    ret = ' ';
                break;
            case 'B':
                if (prev.getAlt() == ' ')
                    ret = ' ';
                else
                    ret = '#';
                break;
            case 'C':
                if (prev.getAlt() == ' ')
                    ret = 'b';
                else
                    ret = ' ';
                break;
            case 'D':
                if (prev.getAlt() == ' ')
                    ret = 'b';
                else
                    ret = ' ';
                break;
            case 'E':
                if (prev.getAlt() == ' ')
                    ret = ' ';
                else
                    ret = '#';
                break;
            case 'F':
                if (prev.getAlt() == '#')
                    ret = ' ';
                else
                    ret = 'b';
                break;
            case 'G':
                if (prev.getAlt() == '#')
                    ret = ' ';
                else
                    ret = 'b';
                break;
            default:
                break;
        }
    }
    return ret;
}

