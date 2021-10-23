//
// Created by souben on 21‏/10‏/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    printf("hello world (pid: %d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed \n");
        exit(1);
    }else if(rc == 0){
        printf("I'm child (pid:%d)\n", (int) getpid());
    }else{
        int wc = wait(NULL);
        printf("I'm parent of %d (pid: %d) (wc:%d)\n", rc, getpid(), wc);
    }
    return 0;
}
