/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egibeaux <egibeaux@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 02:46:20 by egibeaux          #+#    #+#             */
/*   Updated: 2025/05/18 03:56:15 by egibeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	ft_put(int fd, char c, va_list *args)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i' || c == 'u')
		len += ft_putnbr_fd(va_arg(*args, int), fd);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(*args, char *), fd);
	else if (c == 'c')
		len += ft_putchar_fd(va_arg(*args, int), fd);
	else if (c == 'x' || c == 'X')
		len += ft_puthex_fd(va_arg(*args, unsigned int), c, fd);
	else if (c == 'p')
		len += ft_putptr_fd(va_arg(*args, unsigned long long), fd, true);
	else if (c == '%')
		len += ft_putchar_fd('%', fd);
	return (len);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_put(fd, s[i++], &args);
		}
		else
		{
			len += ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	va_end(args);
	return (len);
}

int	main()
{
	char	name[7] = "Elliot\0";
	int		age = 18;

	ft_dprintf(STDERR_FILENO, "this is %s i'm %d or %x my address is %p\n", name, age, age, &name);
	return (0);
}
