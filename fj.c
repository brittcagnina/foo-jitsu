#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "core.h"

#define LFLAG 0b00000001
#define AFLAG 0b00000010

int main(int argc, char** argv)
{
    int oc; // Option character
    char flags = 0x00;
    int hasOption;
 
    if(argc == 1)
    {
	system("ls --color=auto");
	return 0;
    }

    while( (oc = getopt(argc, argv, ":blar:")) != -1)
    {
	if(hasOption == 0)
	    hasOption = 1;

        switch(oc)
        {
	    case 'l' :
		flags |= LFLAG;
		break;
	    case 'a' :
		flags |= AFLAG;
	        break;
	    case 'r' :
		printf("fj removed %s\n", optarg);
		fj_remove(optarg);
		break;
	    case ':' :
		printf(": error\n");
	        break; 
	    case '?' :
		printf("? error\n");
		break;
	    default :
		printf("default error\n");
        }
    }

    if(argc == 2 && !hasOption)
    {
	//TODO: If dir, cd into.  Otherwise vi file.
	fj_editor(argv); // Currently defaults to vi editor
	return 0;
    }

    if(flags == LFLAG) {
	system("ls -l --color=auto");
    }
    if(flags == AFLAG) {
	system("ls -a --color=auto");
    }
    if(flags == (AFLAG | LFLAG)) {
	system("ls -la --color=auto");
    }

    return 0;
}
