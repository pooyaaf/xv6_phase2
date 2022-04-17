#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"
#include "fcntl.h"


// void print_syscalls(int fd,char* pname) {
//     printf(fd, "%s - fork count: %d ", pname, get_call_count(SYS_fork));
//     printf(fd, "%s - write count: %d\n", pname, get_call_count(SYS_write));
// }

int main(int argc,char *argv[])
{
    int parent,child1,child2;
    int fork_sol,write_sol;
    if(argc<1)
        exit();
    parent = getpid();
    child1 = fork();
    if(child1 == 0)
    {
        write(1,"Child1 writes s.t. in command!\n",31);
        fork_sol = get_call_count(SYS_fork);
        write_sol = get_call_count(SYS_write);
        printf(1,"Child1 Process Fork status:%d,Write status:%d \n",fork_sol,write_sol);
        kill(child1);
    }
    sleep(10);
    child2 = fork();

    fork_sol = get_call_count(SYS_fork);
    write_sol = get_call_count(SYS_write);
            
    wait();
    if(child2 == 0){
        printf(1,"Child2 Process Fork status:%d,Write status:%d \n",fork_sol,write_sol);
    }
    else if( (child1!=0) && (child2!=0))
    {
        wait();
        wait();
        //
        printf(1,"Main Process ID: %d \n",parent);
        printf(1,"CHILD ID's 1:%d,2:%d \n",child1,child2);
        printf(1,"Child1 Fork status:%d,Write status:%d \n",fork_sol,write_sol);
        //
        for(int i=0;i<200;i=i+1);
    }
    exit();
    return 0;
}
