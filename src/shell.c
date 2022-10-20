#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//
// Created by shaov on 10/17/2022.
//
int main () {
    int argc = 15; //Max amount of arguments.
    char* argv[argc];
    char* args[argc+1]; //Setting up another array +1 to account for NULL
    printf(": ");
    for (int i = 0; i < argc; i++) {

    }
    if (argc < 1) { //If argc is 0.
        printf("USAGE:\n  CMD ARGS");
        exit(1);
    }

    args[argc] = NULL; //Sets last index of args to NULL
    const char* cmd = argv[1]; //Sets cmd to the second index of argv. First index is ./program

    int counter = 1;
    while (counter < argc) { //Starts putting argv array into args, but counter starts at 1.
        args[counter-1] = argv[counter];
        counter++;
    }

    pid_t pid;
    pid = fork();
    int status;

    if (pid < 0) {
        perror("Failed to fork.");
    }
    else if (pid == 0) {
        execvp(cmd, args);
    }

    waitpid(pid, &status, 0); //Waits for the child process(es) to finish.
    if (WIFEXITED(status)) {
        printf("Program finished.");
    }

    return 0;
}