#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

int main(int argc, char ** argv){

    int begin = getpid();
    int pid = fork();
    int i;

    if(pid > 0){
        for(i = 0; i < 15 && pid > 0; i++){
            pid = fork();
            if(pid < 0)
                printf(1,"errors occur!\n");
        }
        if (pid == 0){
            int j = 0;
            while(j++ < 1000);
            if(getpid() == begin+5) sleep(30);
            
            printf(1,"pid = %d\n",getpid());
            if(getpid() == begin+10){
                printf(1,"pid %d waiting for %d\n",begin+10,begin+5);
                int wpid = waitpid(begin+5);
                printf(1,"success clean %d \n",wpid);
            }
            if(getpid() == begin+5){
                exit();
            }
            exit();
        }
    }else if(pid == 0){
        int j = 0;
        while(j++ < 1000);
        exit();
    }
    exit();
    return 0;
}