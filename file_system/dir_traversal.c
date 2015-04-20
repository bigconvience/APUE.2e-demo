#include "apue.h"
#include "myerr.h"
#include <dirent.h>
#include <limits.h>
#include "path_alloc.h"

typedef int Myfunc(const char *, const struct stat *, int);


static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

#define FTW_F   1;
#define FTW_D   2;
#define FTW_DNR 3;
#define FTW_NS  4;

static char *fullpath;

static int myftw(char *pathname, Myfunc *func)
{
    int len;
    fullpath = path_allo(&len);

    strncpy(fullpath, pathname, len);
    fullpath[len-1] = 0;
    return (dopath(func));
}

static int myfunc(const char *path, const struct stat *statptr, int type)
{
    switch (type) {
        case FTW_F:
            switch (statptr->st_mode & S_IFMT) {
                case S_IFREG:   nreg++; break;
                case S_IFBLK:   nblk++; break;
                case S_IFCHR:   nchr++; break;
                case S_IFFIFO:  nfifo++;    break;
                case S_IFLNK:   nslink++;   break;
                case S_IFSOCK:  nsock++;    break;
                case S_IFDIR:
                                err_dump("for S_IFDIR for %s", pathname);
            }
            break;
        case FTW_D:
            ndir++;
            break;
            
        case FTW_DNR:
            err_ret("can't read directory %s", pathname);
            break;

        case FTW_NS:
            err_ret("stat error for %s", pathname);
            break;

         default:
            err_dump("unknow type %d for pathname %s", type, pathname);
    }
    return 0;
}

            

