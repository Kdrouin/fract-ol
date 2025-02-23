GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
OBJ 		=	$(SRC:.c=.o)
HEADERS	=	libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $<
	@echo "$(NAME): $(GREEN)$@ was created$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean $(NAME)
