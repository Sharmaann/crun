#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commandParser.c"
#include "main.h"

int command_manager(int argcCommand, char **argvCommand){
    char *input = argvCommand[2];
    int argc;
    char **argv;
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }
    parse_command(input, &argc, &argv);
    libcrun_error_t err = NULL;
    int ret, first_argument = 0;

    arguments.argc = argc;
    arguments.argv = argv;

#ifdef DYNLOAD_LIBCRUN
    if (ensure_cloned_binary() < 0)
    {
        fprintf(stderr, "Failed to re-execute libcrun via memory file descriptor\n");
        _exit(EXIT_FAILURE);
    }
    /* Resolve all libcrun weak dependencies.  */
    if (dlopen("libcrun.so", RTLD_GLOBAL | RTLD_DEEPBIND | RTLD_LAZY) == NULL)
        error(EXIT_FAILURE, 0, "dlopen: %s", dlerror());
#endif

    fill_handler_from_argv0(argv[0], &arguments);

    argp_parse(&argp, argc, argv, ARGP_IN_ORDER, &first_argument, &arguments);

    command = get_command(argv[first_argument]);
    if (command == NULL)
        libcrun_fail_with_error(0, "unknown command %s", argv[first_argument]);

    ret = command->handler(&arguments, argc - first_argument, argv + first_argument, &err);
    if (ret && err)
        libcrun_fail_with_error(err->status, "%s", err->msg);
    return ret;
}

void globalConfig(){
    return ;
}
void createContainer() {
    return ;
}
void startContainer(){
    return ;
}
void runContainer(){
    return ;
}
void deleteContainer(){
    return ;
}
void killContainer(){
    return ;
}   

int main(int argc, char **argv){
    command_manager(argc, argv);
}