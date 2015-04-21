#include "apue.h"

int main(void)
{
    char *ptr;
    int size;

    if (chdir("workspace") < 0)
        err_sys("chidr failed");

    ptr = path_alloc(&size);
    if (getcwd(ptr, size) == NULL)
        err_sys("getcwd failed");

    printf("cwd = %s\n", ptr);
    exit(0);
}
