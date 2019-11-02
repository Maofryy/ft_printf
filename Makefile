NAME	= libftprintf.a
SRC		= ft_printf.c ft_flags.c \
		  ft_test.c ft_conv.c \
			ft_buffer.c ft_buffer2.c ft_wide.c ft_conv_str.c \
			ft_int.c ft_conv_ptr.c ft_conv_float.c ft_conv_int.c
OBJ		= $(SRC:.c=.o)


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFLAGS = -Ilibft/includes
LIBFT	= libft/libft.a

GREEN = \033[0;32m
RED = \033[0;31m
WHITE = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) ft_printf.h
	cp $(LIBFT) $@
	ar rcs $@ $(OBJ) && echo "$(GREEN)$@ successfully created$(WHITE)"

$(LIBFT) :
	$(MAKE) -C libft

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

//.SILENT: all $(NAME) clean fclean re

run: $(NAME)
	$(CC) main.c -o test.exe libftprintf.a && ./test.exe
