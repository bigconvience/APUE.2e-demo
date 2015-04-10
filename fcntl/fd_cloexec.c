#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

extern char **environ;
int main(int argc, char *argv[])
{
    int flag;
    int ret;
    flag = fcntl(STDOUT_FILENO, F_GETFD, 0);
    printf("close-on-exec is %d\n", flag);
    fcntl(STDOUT_FILENO, F_SETFD, flag | ~FD_CLOEXEC);
    
    flag = fcntl(1, F_GETFD, 0);
    printf("close-on-exec is %d\n", flag);
    ret = execve("/bin/ls", argv, environ);

    if (ret == -1) {
        printf("FAULT!\n");
    }

    printf("AH!!!!\n");
    return 0;
}

