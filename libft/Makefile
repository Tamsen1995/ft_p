FLAG = -Wall -Werror -Wextra -I ../includes

NAME = libft.a

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_strchr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_count_chars.c \
	ft_remove_char.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_putendl_col.c \
	ft_putstr_col.c \
	free_twod_arr.c \
	ft_strfree.c \
	ft_safe_opendir.c \
	ft_itoa_base.c \
	fatal.c \
	make_file_path.c \
	reverse_string.c \
	adjust_string.c \

OBJ = $(addsuffix .o, $(basename $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C printf
	@gcc $(FLAGS) -I printf/includes -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c libft.h
	clang $(FLAG) -c $< -o $@

clean:
	@make -C printf clean
	rm -f $(OBJ)


fclean: clean
	@make -C printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
