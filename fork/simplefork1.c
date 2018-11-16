#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid, ch_pid;
    int wait_status;
    char *message;
    int n=4, ecode;
    printf("Fork program started\n");
    pid = fork();
    while(n!=0){
        switch(pid){
            case -1: 
                perror("Aaaargh!");
                exit(-1);
            case 0:
                printf("Child pid: %d\n", ch_pid);
                pid = fork();
                break;
            default:
                message = "I am the Parrent!\n";
                n = 3;
                ecode = 0;
                break;
        }
        n-=1;
        sleep(1);
    }

   
    exit(0);
}