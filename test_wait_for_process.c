#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc,char *argv[])
{
	int cid1, cid2;

    cid1 = fork();

    if (cid1 == 0) {
        printf(1, "starting child 1\n");
        sleep(10);
        printf(1, "child 1 ended\n");
        exit();
    }
    else {
        cid2 = fork();
        if (cid2 == 0) {
            printf(1, "child 2 started waiting for child 1\n");
            wait_for_process(cid1);
            printf(1, "child 2 waiting is over\n");
            exit();
        }
        else {
            printf(1, "parent started waiting for child 1\n");
            wait();
            printf(1, "parent waiting is over\n");
            exit();
        }
    }

    exit();
}
