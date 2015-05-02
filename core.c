#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

#include "core.h"

int fj_editor(char** argv)
{
    char* command;
    char* editor_string = "vi ";
    if( (command = malloc(strlen(editor_string) + strlen(argv[1]) + 1)) != NULL)
    {
        command[0] = '\0'; // to be safe
        strcat(command, editor_string);
        strcat(command, argv[1]);
        system(command);
        return 0;
    }
    else
    {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }
}

int fj_remove(char* optarg)
{
    struct stat s;
    int err = stat(optarg, &s);
    if(-1 == err)
    {
        printf("The object, %s,  D.N.E.\n", optarg);
    }
    else
    {
        char* rm_string = "rm -r ";
        char* command;
        if( (command = malloc(strlen(rm_string) + strlen(optarg) + 1)) != NULL )
        {
            command[0] = '\0'; // to be safe
            strcat(command, rm_string);
            strcat(command, optarg);
        }
        else
        {
            fprintf(stderr, "malloc failed!\n");
        }

        if(S_ISDIR(s.st_mode) || S_ISREG(s.st_mode))
        {
	    printf("foo-jitsu removed %s\n", optarg);
            system(command);
        }
        else
        {
            printf("Cannot remove %s\n", optarg);
	    return 1; 
        }
    }

    return 0;
}

