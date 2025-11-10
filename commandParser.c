#include <stdio.h>
#include <cjson/cJSON.h>
#include <string.h>
#include <stdlib.h>
#include "commandParser.h"
#define MAX_ARGS 20
#define MAX_ARG_LEN 100


void parse_command(const char *input, int *argc, char ***argv){
    static char arg_storage[MAX_ARGS][MAX_ARG_LEN];
    static char *arg_pointers[MAX_ARGS];

    *argc = 1;

    char buffer[256];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    char *token = strtok(buffer, " ");
    while (token != NULL && *argc < MAX_ARGS)
    {
        strncpy(arg_storage[*argc], token, MAX_ARG_LEN - 1);
        arg_storage[*argc][MAX_ARG_LEN - 1] = '\0';
        arg_pointers[*argc] = arg_storage[*argc];
        (*argc)++;
        token = strtok(NULL, " ");
    }

    *argv = arg_pointers;
}
