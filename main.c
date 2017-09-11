#include "apue.h"
#include <sys/wait.h>

#define	DEF_PAGER	"/usr/bin/more"		/* default pager program */

int
main(int argc, char *argv[])
{
    printf("uid = %d, gid = %d, euid = %d, egid = %d\n", getuid(), getgid(), geteuid(), getegid());
    exit(0);
}
