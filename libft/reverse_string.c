#include "../includes/libft.h"

/*
** a utility to reverse a string
** it allocates a new string which will be
** the reverse of the given string
*/

char *reverse_string(char *str)
{
	int i;
	int str_len;
	char *ret;

	i = 0;
	ret = NULL;
	str_len = ft_strlen(str) - 1;
	if (!str)
		return (NULL);
	ret = ft_strnew(ft_strlen(str));
	while (str[i] && str_len > -1)
	{
		ret[i] = str[str_len];
		str_len--;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
