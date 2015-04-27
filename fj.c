#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "core.h"

int main(int argc, char** argv)
{
    int oc; //option character
    char* b_opt_arg;
	
    if(argc == 1)
    {
	system("ls --color=auto");
	return 0;
    }
    else if(argc == 2)
    {
	fj_editor(argv);
	return 0;
    }

    while( (oc = getopt(argc, argv, "alr:b:")) != -1)
    {
        switch(oc)
        {
	    case 'a' :
	        printf("option a has been recognized\n"); 
	        break;
	    case 'b' :
	        // handle -b, getr arg value from optarg
	        b_opt_arg = optarg;
	        printf("option argument passed was: %s\n", b_opt_arg);
		break;
	    case 'l' :
		system("ls -l --color=auto");
		break;
	    case 'r' :
		printf(" -r recognized\n");
		fj_remove(optarg);
		break;
	    case ':' :
		printf(": error\n");
	        //err handling
	    case '?' :
		printf("? error\n");
	    default :
		printf("default error\n");
	        //err handling
        }
    }

    return 0;
}
