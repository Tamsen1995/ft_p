
#include "libftprintf.h"

int		sym_int(char const *str, int i)
{
	return (str[i + 1] == '#' || str[i + 1] == '-' ||
	(str[i + 1] == '.' && (str[i + 2] == 'd' || str[i + 2] == 'i')));
}

int		symb_int(char const *str, int *i)
{
	return (str[*i + 1] == 'd' || str[*i + 1] == 'i' ||
	((str[*i + 1] == ' ' || str[*i + 1] == '+') &&
	(str[*i + 2] == 'd' || str[*i + 2] == 'i')));
}

int		sym_char(char const *str, int *i)
{
	return (str[*i + 1] == 'c' || ((str[*i + 1] == ' ' ||
	str[*i + 1] == '+' || str[*i + 1] == '.') && str[*i + 2] == 'c'));
}
