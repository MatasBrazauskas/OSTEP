#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LENGTH 30

int main(int argc, char *argv[])
{
    char str[MAX_LENGTH];
    char* commandArgs[] = {"main.c", NULL};

    printf("Enter command to performe: ");
    scanf("%s", str);

    int rc = fork();

    if(rc < 0){ fprintf(stderr, "Error");}
    else if(rc == 0){
        execvp(str, commandArgs);
        printf("Code, after exe, will not run!");
    }else{
        int wc = wait(NULL);
        printf("Command has been executed.\n");
    }


    return 0;
}