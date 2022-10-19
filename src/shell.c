//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include <unistd.h>
//#include <sys/wait.h>
//
////
//// Created by shaov on 10/17/2022.
////
//int main (int argc, char* argv[]) {
//    printf("$ ");
//    if (argc != 2) {
//        printf("USAGE: \nPROGRAM TO RUN.");
//        exit(1);
//    }
//
//    pid_t pid;
//    pid = fork();
//
//    if (pid < 0) {
//        perror("Failed to fork.");
//    }
//    //Loop over the argv and then fill in the args with the args.
//    else if (pid == 0) {
//        char* args[] = { argv[1] };
//    }
//
//    return 0;
//}