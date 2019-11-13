
CC = gcc
FLAGS = -g -Wall -Wextra -Werror -I includes
PRINTF = libft/printf/libftprintf.a
LIBFT = libft/libft.a

NAME_se = server
NAME_cli = client

SRC_se = src/server.c \
		src/get_next_line.c



SRC_cli = src/client.c \
		src/get_next_line.c


OBJ_se = $(addsuffix .o, $(basename $(SRC_se)))
OBJ_cli = $(addsuffix .o, $(basename $(SRC_cli)))

all: $(LIBFT) $(NAME_se) $(NAME_cli)

$(LIBFT):
	make -C libft

$(NAME_se):$(LIBFT) $(NAME_se) $(OBJ_se)
	@echo "building binary file"
	$(CC) $(FLAGS) $(SRC_se) -o $(NAME_se) -I -lft $(LIBFT) $(PRINTF)

$(NAME_cli):$(LIBFT) $(NAME_cli) $(OBJ_cli)
	@echo "building client binary file"
	$(CC) $(FLAGS) $(SRC_cli) -o $(NAME_cli) -I -lft $(LIBFT) $(PRINTF)

%.o: %.c ft_ls.h
		clang $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ_se)
	rm -rf $(OBJ_cli)
	@make clean -C libft/
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME_se)"
	@rm -f $(NAME_se)
	@rm -rf $(NAME_cli)
	rm -rf server.dSYM
	rm -rf client.dSYM
	rm -rf server_dir 
	@make fclean -C libft/
# TESTING : The remove server_dir should be removed soon once the existing folder case has been handled
re: fclean all

.PHONY: re clean fclean all