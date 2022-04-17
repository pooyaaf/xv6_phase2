#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc,char *argv[])
{
	if(argc != 2) {
	    printf(1, "Please enter only one argument\n");
		exit();
	}

    int num = atoi(argv[1]);
    printf(1, "next prime number = %d\n" , find_prime_number(num));

    exit();
}
