#include "../includes/libft.h"

char *ft_strchr(char *s, int c)
{
	char *ret;

	ret = NULL;
	if (!s)
		return (NULL);
	ret = s;
	while (*ret)
	{
		if (*ret == c)
			return (ret);
		ret++;
	}
	return (NULL);
}

