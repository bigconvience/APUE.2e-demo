#include	<stropts.
#include	<unistd.h>

int
isastream(int fd)
{
	return(ioctl(fd, I_CANPUT, 0) != -1);
}
