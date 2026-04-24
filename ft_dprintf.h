#ifndef FT_DPRINTF_H
#define FT_DPRINTF_H

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int          ft_putchar_fd(char c, int fd);
int          ft_putstr_fd(char *s, int fd);
int          ft_putnbr_fd(long nbr, int fd);
int          ft_dprintf(int fd, const char *s, ...);
int          ft_puthex_fd(unsigned int nbr, char c, int fd);
int          ft_putptr_fd(unsigned long long nbr, int fd, bool is_first);
unsigned int ft_atoi(const char *str);
unsigned int getValue(const char *s);
int          ft_isdigit(int c);

#endif
