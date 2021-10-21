
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"


int main(int argc, char *argv[]){
    int *p;
    p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) adress of p: %p\n", getpid(), p);

    *p = 0;
    while(1){
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %p\n", getpid(), p);
    }
    return 0;

}