#include "ft_dprintf.h"

int	ft_putptr_fd(unsigned long long nbr, int fd, bool is_first)
{
	if (is_first)
	{
		is_first = false;
		if (!nbr)
			return (ft_putstr_fd("(nil)", fd));
		return (ft_putstr_fd("0x", fd) + ft_putptr_fd(nbr, fd, is_first));
	}

	if (nbr >= 16) {
          return (ft_putptr_fd(nbr / 16, fd, 0) +
                  ft_putptr_fd(nbr % 16, fd, 0));
	}
	else
	{
		if (nbr <= 9)
			return (ft_putchar_fd(nbr + '0', fd));
		else
			return (ft_putchar_fd((nbr - 10) + 'a', fd));
	}
}
