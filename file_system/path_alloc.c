#include "apue.h"
#include "myerr.h"
#include <error.h>
#include <limits.h>

#ifdef pathmax
static int pathmax = pathmax;
#else
static int pathmax = 0;
#endif

#define SUSV3   200112L

static long posix_version = 0;

#define PATH_MAX_GUESS  1024

char * path_alloc(int *sizep)
{
    char *ptr;
    int size;

    if (posix_version == 0) {
        posix_version = sysconf(_SC_VERSION);
        printf("posix version %ld\n", posix_version);
    }

    if (pathmax == 0) {
        errno = 0;

        if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
            if (errno == 0)
                pathmax = PATH_MAX_GUESS;
            else 
                err_sys("pathconf error for _PC_pathmax");
        } else {
            pathmax++;
        }
    }
    printf("pathmax: %d\n", pathmax);
    if (posix_version < SUSV3)
        size = pathmax + 1;
    else 
        size = pathmax;

    if ((ptr = malloc(size)) == NULL)
        err_sys("malloc error for pathname");

    if (sizep != NULL)
        *sizep = size;
    printf("malloc %d success\n", size);
    
    return (ptr);
}
