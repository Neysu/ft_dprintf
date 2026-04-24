#include "ft_dprintf.h"

int		ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
