NAME	= libftprintf.a
SRC		= ft_printf.c ft_args.c ft_check.c  ft_flags.c \
		  ft_ftoa.c ft_test.c ft_conv.c
OBJ		= $(SRC:.c=.o)


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFLAGS = -Ilibft/includes
LIBFT	= libft/libft.a


all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	$(MAKE) -C libft
	mv $(LIBFT) $@
	ar rcs $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFLAGS) -o $@ -c $<

clean:
	$(MAKE) -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
