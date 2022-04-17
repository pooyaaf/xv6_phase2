#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char* argv[])
{
    int pid = getpid();
    printf(1, "process pid: %d\n", pid);
    
    exit();
    return 0;
}