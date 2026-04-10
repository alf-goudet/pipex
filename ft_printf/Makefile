NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_convs.c ft_printf_utils.c \
	   ft_printf_convs_long.c ft_printf_utils_long.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = -C libft

.PHONY: all sub_libft clean fclean re

all: sub_libft $(NAME)

sub_libft:
	$(MAKE) $(LIBFT_PATH)

$(NAME): $(OBJS)
	ar rc $@ $^

clean:
	$(MAKE) $@ $(LIBFT_PATH)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) $@ $(LIBFT_PATH)
	rm -f $(NAME)	

re: fclean all
