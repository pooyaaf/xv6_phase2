#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc,char *argv[])
{
    int num = atoi(argv[1]);
    asm("mov %0, %%ebx;"
    :
    :"r"(num)
    );
    
    //
    
    printf(1,"Next prime is -->  %d\n",find_prime_number());
    
    exit();
}
