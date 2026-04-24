#include "ft_dprintf.h"

int	ft_puthex_fd(unsigned int nbr, char c,int fd)
{
	if (nbr >= 16)
		return (ft_puthex_fd(nbr / 16, c, fd) + ft_puthex_fd(nbr % 16, c, fd));
	else 
	{
		if (nbr <= 9)
			return (ft_putchar_fd(nbr + '0', fd));
		else
		{
			if ( c == 'x')
				return (ft_putchar_fd((nbr - 10)+ 'a', fd));
			else if (c == 'X')
				return (ft_putchar_fd((nbr - 10) + 'A', fd));
		}
	}
	return (0);
}
