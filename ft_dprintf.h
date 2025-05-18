/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egibeaux <egibeaux@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 03:45:30 by egibeaux          #+#    #+#             */
/*   Updated: 2025/05/18 03:49:07 by egibeaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long nbr, int fd);
int		ft_dprintf(int fd, const char *s, ...);
int		ft_puthex_fd(unsigned int nbr, char c,int fd);
int		ft_putptr_fd(unsigned long long nbr, int fd, bool is_first);

#endif
