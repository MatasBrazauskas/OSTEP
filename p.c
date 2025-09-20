#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    char* myargs[] = {"ls", NULL};
    execvp(myargs[0], myargs);    
    printf("This is a end of p process: %d\n", (int)getpid());
    return 0;
}