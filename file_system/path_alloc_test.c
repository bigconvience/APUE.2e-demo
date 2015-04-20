#include <stdio.h>
#include "path_alloc.h"

int main(void)
{
    int size;
    char * ptr = path_alloc(&size);
    if (ptr != NULL)
        printf("path alloc %d success\n", size);
    else 
        printf("failed\n");
    
    return 0;
}

