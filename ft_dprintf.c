#include "ft_dprintf.h"

static int ft_put(int fd, char c, va_list *args) {
    int len;

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

int ft_dprintf(int fd, const char *s, ...) {
    unsigned int size;
    va_list      args;
    int          len = 0;
    int          i   = 0;

    va_start(args, s);
    while (s[i]) {
        if (s[i] != '%') {
            len += ft_putchar_fd(s[i], fd);
            i++;
        } else {
            i++;
            if (s[i] == '+') {
                i++;
                size = getValue(s + i);
            } else if (s[i] == '-') {
                i++;
                size = getValue(s + i);
                dprintf(STDOUT_FILENO, "%c %d\n", s[i], size);
            } else
                len += ft_put(fd, s[i++], &args);
        }
    }
    va_end(args);
    return (len);
}
