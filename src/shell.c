#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim){
    char** result = 0;
    size_t count = 0;
    char* tmp = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    while (*tmp){
        if (a_delim == *tmp){
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    count += last_comma < (a_str + strlen(a_str) - 1);

    count++;

    result = malloc(sizeof(char*) * count);

    if (result){
        size_t i  = 0;
        char* split = strtok(a_str, delim);

        while (split) {
            assert(i < count);
            *(result + i++) = strdup(split);
            split = strtok(0, delim);
        }
        if (i != count - 1) {
            printf("USAGE:\n  CMD ARGS");
            return NULL;
        }
        *(result + i) = 0;
    }
    return result;
}

int main() {
    for(;;) {
        printf("\n$");
        char inputArgs[500];
        scanf(" %499[^\n]s", inputArgs);
        char **argsv = str_split(inputArgs, ' ');
        if (argsv) {
            if(strcmp(argsv[0], "exit") == 0) {
                break;
            }
            int status;
            pid_t pid = fork();
            if (pid < 0) {
                perror("Fork failed.");
                return 1;
            } else if (pid == 0) {
                if (execvp(argsv[0], argsv) < 0) {
                    perror("Incorrect execv.");
                    exit(1);
                }
                else {
                    printf("%d", execvp(argsv[0], argsv));
                    exit(0);
                }
            }
            waitpid(pid, &status, 0);
            free(argsv);
        }
    }

}