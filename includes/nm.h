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

typedef struct s_symbols
{
	unsigned long value;
	char type;
	char *name;
	struct s_symbols *next;
	struct s_symbols *prev;
} t_symbols;

typedef struct s_section
{
	char *name;
	unsigned int nb;
	struct s_section *next;
	struct s_section *prev;
} t_section;

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

/*
** functions created during the otool
*/
void go_fat_big(char *ptr);
void go_fat_lil(char *ptr);
void output_sections_64(char *ptr, t_section_list *sec_list, char *filename);
void output_sections_32(char *ptr, t_section_list *sec_list, char *filename);
void ft_otool(char *ptr, char *filename);
void make_sec_list(char *ptr, char *filename, T_BOOL is_64);
void add_sec(t_section_list **sec_list, struct section *sec, struct section_64 *sec_64);
void go_archive(char *ptr, char *filename);
void process_archs(char *ptr, t_ran_offset *list, char *filename);
int get_archive_size(char *name);

/*
** These functions were made for the nm
*/

void ft_nm(char *ptr);
char determine_type(uint32_t type, uint32_t n_sect, t_lsection *sec_list, int addr);
void handle_64(char *ptr);
t_lsection *get_sections_64(char *ptr);
void process_symtab_64(struct symtab_command *sym, char *ptr, t_lsection *sec_list);
void add_symbols_64(char *strable, struct nlist_64 list, t_lsection *sec_list, t_symbols **sym_list);
void handle_32(char *ptr);
t_lsection *get_sections_32(char *ptr);
void process_symtab_32(struct symtab_command *sym, char *ptr, t_lsection *sec_list);
void add_symbols_32(char *strtable, struct nlist list, t_lsection *sec_list, t_symbols **sym_list);
void handle_fat_big(char *ptr);
void handle_fat_lil(char *ptr);

void add_to_list(char *sectname, t_lsection *list);
t_symbols *add_before(t_symbols *add_bef_this, t_symbols *add);
uint32_t swap_uint32(uint32_t val);
t_symbols *bubble_sort(t_symbols *sym_list);
t_symbols *del_dupl_nd_stabs(t_symbols *sym_list);
void free_sec_list_nm(t_lsection *sec_list);

/*
Testing functions
*/

void print_symbols(t_symbols *sym_list, T_BOOL is_64);
void print_syms_prev(t_symbols *sym_list);

#endif
