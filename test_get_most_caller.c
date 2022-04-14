#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int main(int argc,char *argv[])
{
    printf(1, "most fork call by: %d\n", get_most_caller(SYS_fork));
    printf(1, "most write call by: %d\n", get_most_caller(SYS_write));
    printf(1, "most wait call by: %d\n", get_most_caller(SYS_wait));

    exit();
}
