NAME	= libftprintf.a
SRC		= ft_printf.c ft_args.c ft_check.c  ft_flags.c \
		  ft_ftoa.c ft_test.c ft_conv.c ft_modifiers.c
OBJ		= $(SRC:.c=.o)


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFLAGS = -Ilibft/includes
LIBFT	= libft/libft.a

GREEN = \033[0;32m
RED = \033[0;31m
WHITE = \033[0m

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	$(MAKE) -C libft
	cp $(LIBFT) $@
	ar rcs $@ $(OBJ) && echo "$(GREEN)$@ successfully created$(WHITE)"

%.o: %.c
	@$(CC) $(CFLAGS) $(LIBFLAGS) -o $@ -c $< && echo "$(GREEN)$@$(WHITE)"

clean:
	$(MAKE) -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) clean fclean re

run: $(NAME)
	$(CC) $(CFLAGS) -g main.c -o test.out libftprintf.a && ./test.out
