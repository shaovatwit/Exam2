#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//
// Created by shaov on 10/17/2022.
//
int main (int argc, char* argv[]) {
    printf("$ ");
    if (argc != 1) {
        printf("USAGE: \nPROGRAM TO RUN.");
        exit(1);
    }

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Failed to fork.");
    }
    //Loop over the argv and then fill in the args with the args.
    else if (pid == 0) {
        char* firstArgv[] = { argv[0] };
//        char* args = malloc(argc * sizeof(char));
        for (int i = 1; i < argc; i++) {
            argv[i-1] = argv[i];
        }
        execvp((const char *) firstArgv, argv);
    }

    return 0;
}