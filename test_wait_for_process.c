#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc,char *argv[])
{
	int cid1, cid2;

    cid1 = fork();

    if (cid1 == 0) {
        printf(1, "starting child 1\n");
        int i = 0;
        while (i++ < 1000000000);
        printf(1, "child 1 is done\n");
        exit();
    }
    else {
        cid2 = fork();
        if (cid2 == 0) {
            wait_for_process(cid1);
            printf(1, "child 2 waiting is over\n");
            exit();
        }
        else {
            wait();
            exit();
        }
    }
    exit();
    return 0;
}
