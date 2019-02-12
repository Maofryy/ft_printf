CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH =

OBJ_PATH =

CPPFLAGS = -Ilibft/includes

LDFLAGS = -Llibft
LDLIBS = -lftprintf
LDLIB = libftprintf.a

NAME = main.out

SRC_NAME = main.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

GREEN = \033[0;32m
RED = \033[0;31m
WHITE = \033[0m

all : $(NAME)

$(NAME) : lib $(OBJ) 
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@$(WHITE)"

lib : 
ifeq ($(findstring libftprintf.a,$(shell ls libft)),$(LDLIB))
	@echo "$(GREEN)libft already compiled.$(WHITE)"
else
	@make -C libft re && echo "$(GREEN)libft compiled successfully$(WHITE)"
endif

clean :
	@make -C libft clean
	@rm -f $(OBJ) && echo "$(RED)objects successfully deleted$(WHITE)"

fclean : clean
	@make -C libft fclean
	@rm -f $(NAME) && echo "$(RED)$(NAME) deleted$(WHITE)"

re : fclean 
	@make

test : 
ifeq ($(findstring libftprintf.a,$(shell ls libft)),$(LDLIB))
	@echo "$(GREEN)trouve$(WHITE)"
else
	@echo "$(GREEN)pas trouve$(WHITE)"
endif

run : ./$(NAME) 
	@./$(NAME) ${ARGS}

rerun : re run
.PHONY : all clean fclean re lib

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
