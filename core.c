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
        command[0] = '\0';
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
    char* b_opt_arg;
    b_opt_arg = optarg;

    struct stat s;
    int err = stat(b_opt_arg, &s);
    if(-1 == err)
    {
        printf("this dir D.N.E.\n");
    }
    else
    {
        char* rm_string = "rm -r";
        char* command;
        if( (command = malloc(strlen(rm_string) + strlen(b_opt_arg) + 1)) != NULL )
        {
            command[0] = '\0'; //insurance
            strcat(command, "rm -r ");
            strcat(command, b_opt_arg);
        }
        else
        {
            fprintf(stderr, "malloc failed!\n");
        }

        if(S_ISDIR(s.st_mode))
        {
            system(command);
        }
        else if(S_ISREG(s.st_mode))
        {
            system(command);
        }
    }

    return 0;
}

