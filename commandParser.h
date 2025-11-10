#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <stdio.h>
#include <cjson/cJSON.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARGS 20
#define MAX_ARG_LEN 100

/**
 * @brief Parses a command string into individual arguments.
 * 
 * @param input The command string to parse.
 * @param argc Pointer to the number of arguments parsed.
 * @param argv Pointer to an array of argument pointers.
 */
void parse_command(const char *input, int *argc, char ***argv);

#endif // COMMAND_PARSER_H
