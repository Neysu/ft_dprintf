NAME    = ft_dprintf.a
CC      = clang
CFLAGS  = -Wall -Wextra -Werror -g
AR      = ar rcs
RM      = rm -f

SRCS    = ft_dprintf.c \
	  ft_dprintf_utils.c \
	  ft_putptr_fd.c \
	  ft_putstr_fd.c \
	  ft_putchar_fd.c \
	  ft_putnbr_fd.c \
	  ft_puthex_fd.c \

OBJS    = $(SRCS:.c=.o)
HEADERS = ft_dprintf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

