#ifndef NM_H
#define NM_H

#define PROT PROT_READ | PROT_WRITE
#define ANON MAP_PRIVATE | MAP_ANONYMOUS

#define TXT "__TEXT"
#define TUT "__text"
#define BUFF_SIZE 8

#include "./libft.h"
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>
#include <ar.h>
#include <mach-o/ranlib.h>
#include <termcap.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/param.h>
#include <signal.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_server_truth
{
	char *server_dir_path;
} t_server_truth;

/*
** the s_lsection function
** is used only exclusively in the nm
*/

typedef struct s_lsection
{
	struct s_section *first;
	struct s_section *last;
} t_lsection;

/*
** For the otool I will use a more versatile
** struct. The s_section_list will take a
** struct section * including all the crucial
** information which we'll need
*/

typedef struct s_section_list
{
	struct section_64 *section_64;
	struct section *section_32;
	struct s_section_list *next;
	struct s_section_list *prev;
} t_section_list;

/*
** in the otool I need a structure which ensures me
** access to all the offsets of the ranlib indexes
** all the offsets of the ranlib for me
*/

typedef struct s_ran_offset
{
	uint32_t offset;
	uint32_t strx;
	struct s_ran_offset *next;
	struct s_ran_offset *prev;
} t_ran_offset;

/*
** GNL
*/

int get_next_line(int const fd, char **line);
void manage_client(int cs, struct s_server_truth *server_truth);
int create_server(int port);
char *make_server_directory();
void usage(char *str);
void accept_client(int sock, struct s_server_truth *server_truth);
void manage_client(int cs, struct s_server_truth *server_truth);
void relay_commands(char *buf, struct s_server_truth *server_truth);

#endif
