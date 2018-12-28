
CC = gcc
FLAGS = -g -Wall -Wextra -Werror -I includes
PRINTF = libft/printf/libftprintf.a
LIBFT = libft/libft.a

NAME_ot = server

SRC_ot = src/main.c

OBJ_ot = $(addsuffix .o, $(basename $(SRC_ot)))

all: $(LIBFT) $(NAME_ot) 

$(LIBFT):
	make -C libft

$(NAME_ot):$(LIBFT) $(NAME_ot) $(OBJ_ot)
	@echo "building binary file"
	$(CC) $(FLAGS) $(SRC_ot) -o $(NAME_ot) -I -lft $(LIBFT) $(PRINTF)

%.o: %.c ft_ls.h
		clang $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ_ot)
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME_ot)"
	@rm -f $(NAME_ot)
	rm -rf server.dSYM
	@make fclean -C libft/

re: fclean all

.PHONY: re clean fclean all