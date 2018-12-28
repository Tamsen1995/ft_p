/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 06:25:27 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 18:48:56 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/resource.h>
# include <sys/mman.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <fcntl.h>
# include "../libft/printf/includes/libftprintf.h"


# define T_BOOL int
# define TRUE 1
# define FALSE 0

# define VALID_FLAGS	"Ralrt1"
# define NB_FLAGS		6
# define STOP "\033[0;0m"
# define EOC "\033[39m"
# define EOBG "\033[49m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[1m"
# define BLACK "\033[30m"
# define WHITE "\033[97m"
# define BLUE "\033[34m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GRAY "\033[37m"
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGLIGHT "\033[47m"
# define BGGRAY "\033[47m"

typedef enum		e_flgs
{
	f_recur = 0,
	f_hidden = 1,
	f_list = 2,
	f_rev = 3,
	f_time = 4,
	f_main = 5
}					t_flags;

typedef enum		e_filetype
{
	BLOCK,
	CHAR_SP,
	DIRECTORY,
	SYMLINK,
	SOCK_LINK,
	FIFO,
	REG,
	INVALID
}					t_filetype;

/*
** These are mostly for the output of the long listing format
** When I actually need to compare stats like time for example, re-call stat
*/

typedef struct		s_fields
{
	char			mode[11];
	char			*links;
	char			*owner;
	char			*group;
	char			*major;
	char			*size;
	char			*date;
	long long int	st_blocks;
}					t_fields;

typedef struct		s_stack
{
	char				*path;
	char				*filename;
	t_filetype			type;
	struct stat			stats;
	t_fields			*fields;
	struct s_stack		*subdir;
	struct s_stack		*next;
	struct s_stack		*prev;
}					t_stack;

char				*adjust_str(char *str, size_t x);
char				*ft_itoa_base(int num, int base);
char				*reverse_string(char *str);
char				*ft_strchr(char *s, int c);
int					ft_count_chars(char *string, char c);
char				*ft_remove_char(char *string, char c);
char				*make_file_path(char *dir_path, char *filename);
DIR					*safe_opendir(char *dir_path);
void				ft_strfree(char *string);
void				ft_putstr_col(t_stack *file);
void				ft_putendl_col(t_stack *file);
void				free_twod_arr(char **arr);
t_filetype			get_file_type(struct dirent *ent);
size_t				ft_strlen(char const *s);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
void				ft_exit(char *s);
void				ft_init_tab(char **tab);
void				ft_memdel(void **ap);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t n);
void				ft_strlclr(char *s);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbrn(int n);
void				ft_putnbrendl(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_strclr(char *s);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_clear_tab(char ***tab);
void				ft_colstr(char *col, char *msg);
void				ft_strcol(char *col, char *o, char *t, char *l);
int					ft_atoi(char const *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isdigitand(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strrchr(char const *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strdup(char const *s1);
char				*ft_strndup(char const *s1, int i);
char				*ft_strstr(char const *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				*ft_strctrim(const char *s, char c);
char				*ft_split_char(char *s, int i, char c);
char				**ft_strsplit(const char *s, char c);
void				ft_list_push_back(t_stack **alst, \
struct dirent *ent, char *path, char *flags);
void				fatal(char *err_msg);

#endif
