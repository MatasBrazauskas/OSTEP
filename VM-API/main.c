#include <stdio.h>
#include <stdlib.h>
#include  <signal.h>

void trapHandler();

int main(int argc, char** argv){

    signal(SIGINT, &trapHandler);

    if(argc != 2){
        fprintf(stderr, "Error: not enought command line arguments\n");
        return 1;
    }

    char* endPtr;
    long int num;

    num = strtol(argv[1], &endPtr, 10);

    if(*endPtr != '\0'){
        return 1;
    }

    printf("%ld\n", num);

    int* arr = malloc(num);
    int index = 0;

    while(index < num){
        /*if(index >= num){
            index = 0;
        }*/

        printf("Index: %d, Number: %d\n", index, arr[index]);
        ++index;

        int* j = malloc(10 * sizeof(int));
    }

    return 0;
}

void trapHandler(){
    printf("Process is stopping\n");
    exit(1);
}