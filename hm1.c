#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int x = 100;

    int fr = fork();

    if(fr == 0){
        x = 102;
        printf("Child - %d\n", x);
    }else{
        x = 101;
        printf("Parent - %d\n", x);
    }
    
    return 0;
}