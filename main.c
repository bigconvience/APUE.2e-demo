#include "apue.h"


#define offset(TYPE, MEMBER) ((int)&((TYPE *)0)->MEMBER)

struct person {
    int age;
    char tal;
    char *name;
};

int
main(int argc, char *argv[])
{
    printf("uid = %d, gid = %d, euid = %d, egid = %d\n", getuid(), getgid(), geteuid(), getegid());

    printf("offset %d\n", offset(struct person, name));
    exit(0);
}
