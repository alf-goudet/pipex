NAME = pipex

LIB = libpipex.a
LIBFTPRINTF = ft_printf/libftprintf.a
LIBFT = ft_printf/libft/libft.a
LIBS = $(LIB) $(LIBFTPRINTF) $(LIBFT)

SRCS = pipex.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_PATH = -C ft_printf

all: sub_ft_printf $(NAME)

sub_ft_printf:
	$(MAKE) $(FT_PRINTF_PATH)

$(NAME): $(OBJS)
	ar rc $(LIB) $^
	$(CC) $(CFLAGS) $(LIBS) -o $@

clean:
	$(MAKE) $@ $(FT_PRINTF_PATH)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) $@ $(FT_PRINTF_PATH)
	rm -f $(LIB) $(NAME)

re: fclean all
