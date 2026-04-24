#include "ft_dprintf.h"

int	ft_putnbr_fd(long nbr, int fd)
{
	if (nbr == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		return (1 + ft_putnbr_fd(-nbr, fd));
	}
	if (nbr > 9)
		return (ft_putnbr_fd(nbr / 10, fd) + ft_putnbr_fd(nbr % 10, fd));
	return (ft_putchar_fd(nbr + '0', fd));
}
