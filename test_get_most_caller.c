#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int main(int argc,char *argv[])
{
    // int child1,child2;
    // if(argc<1)
    //     exit();
   
    // child1=fork();
    // if(child1==0){
    //     write(1,"Child1 write says ... \n",31);
    //     kill(child1);
    // }
    // sleep(10);
    // child2 = fork();
    // wait();
    // if(child2 == 0 ){
    //     write(1,"Child2 says ...\n",31);
    // }
    // else if((child1!=0)&&(child2!=0)){
    //     wait();
    //     wait();
    //     //
    //         printf(1, "most fork call by: %d\n", get_most_caller(SYS_fork));
    //         printf(1, "most write call by: %d\n", get_most_caller(SYS_write));
    //         printf(1, "most wait call by: %d\n", get_most_caller(SYS_wait));
    //     for(int i=0;i<200;i++);
    // }
            printf(1, "most fork call by: %d\n", get_most_caller(SYS_fork));
            printf(1, "most write call by: %d\n", get_most_caller(SYS_write));
            printf(1, "most wait call by: %d\n", get_most_caller(SYS_wait));
    exit();
}

