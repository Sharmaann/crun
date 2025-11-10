#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

void parse_command(const char *input, int *argc, char ***argv);
int command_manager();
void globalConfig();
void createContainer();
void startContainer();
void runContainer();
void deleteContainer();
void killContainer();
#endif // COMMAND_MANAGER_H