#include "ft_dprintf.h"

unsigned int ft_atoi(const char *str) {
    int i;
    int result;
    int sign;

    sign   = 1;
    result = 0;
    i      = 0;
    while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
           str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}

int ft_isdigit(int c) { return (c >= '0' && c <= '9'); }

unsigned int getValue(const char *s) {
    int i = 0;

    while (ft_isdigit(s[i]))
        i++;
    return (ft_atoi(s + i));
}
