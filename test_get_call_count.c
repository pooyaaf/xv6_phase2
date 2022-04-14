#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

void print_syscalls(char* pname) {
    printf(1, "%s - fork count: %d ", pname, get_call_count(SYS_fork));
    printf(1, "%s - write count: %d\n", pname, get_call_count(SYS_write));
}

int main(int argc,char *argv[])
{
    if (fork() == 0) {
        print_syscalls("first child");
        exit();
    }
    else {
        if (fork() == 0) {
            print_syscalls("second child");
            exit();
        }
        else {
            wait();
            print_syscalls("parent");
            exit();
        }
    }

    exit();
}
