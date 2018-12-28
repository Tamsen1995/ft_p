#include "../includes/libft.h"

static char read_tab(int i)
{
	char *tab;

	tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	return (tab[i]);
}

char *ft_itoa_base(int num, int base)
{
	int i;
	unsigned int unsigned_val;
	char *str;
	char *ret;

	i = 0;
	str = ft_strnew(50);
	ret = NULL;
	unsigned_val = (unsigned int)num;
	while (unsigned_val > 0)
	{
		str[i] = read_tab(unsigned_val % base);
		unsigned_val = unsigned_val / base;
		i++;
	}
	str[i] = '\0';
	ret = reverse_string(str);
	free(str);
	return (ret);
}