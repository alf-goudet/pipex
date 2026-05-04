NAME = pipex

LIB = libpipex.a
LIBFTPRINTF = ft_printf/libftprintf.a
LIBFT = ft_printf/libft/libft.a
LIBS = $(LIB) $(LIBFTPRINTF) $(LIBFT)

SRCS = pipex.c error_handle.c path_parser.c free_double_ptr.c cmd_runner.c \
	   put_redir.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

FT_PRINTF_PATH = -C ft_printf

all: sub_ft_printf $(NAME)

sub_ft_printf:
	$(MAKE) $(FT_PRINTF_PATH)

$(NAME): $(OBJS)
	ar rc $(LIB) $^
	$(CC) $(CFLAGS) $(LIBS) -o $@

clean:
	$(MAKE) $@ $(FT_PRINTF_PATH)
	rm -f $(OBJS) $(LIB)

fclean: clean
	$(MAKE) $@ $(FT_PRINTF_PATH)
	rm -f $(NAME)

re: fclean all

