#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    int* ptr = malloc(10 * sizeof(int));

    int temp = *ptr;

    return 0;
}