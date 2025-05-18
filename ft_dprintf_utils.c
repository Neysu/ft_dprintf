/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elliot <elliot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 03:01:28 by egibeaux          #+#    #+#             */
/*   Updated: 2025/05/18 18:18:47 by elliot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int		ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int		ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;

	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}

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

int	ft_putptr_fd(unsigned long long nbr, int fd, bool is_first)
{
	if (is_first)
	{
		is_first = false;
		if (!nbr)
			return (ft_putstr_fd("(nil)", fd));
		return (ft_putstr_fd("0x", fd) + ft_putptr_fd(nbr, fd, is_first));
	}

	if (nbr >= 16)
		return (ft_putptr_fd(nbr / 16, fd, 0) + ft_putptr_fd(nbr % 16, fd, 0));
	else
	{
		if (nbr <= 9)
			return (ft_putchar_fd(nbr + '0', fd));
		else
			return (ft_putchar_fd((nbr - 10) + 'a', fd));
	}
}

