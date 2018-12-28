#include "../includes/libft.h"

/*
** Adds padding to a string
*/

static char *pad_string(char *str, size_t x)
{
	char *ret;
	size_t i;

	i = 0;
	ret = NULL;
	if (!str || (x < ft_strlen(str)))
		return (str);
	ret = ft_strnew(x + 1);
	while (i < (x - ft_strlen(str)))
		ret[i++] = '0';
	x = 0;
	while (str[x])
		ret[i++] = str[x++];
	ret[i] = '\0';
	return (ret);
}

/*
** adjusts a string according to x bytes
** if x is smaller than the strlen then
** the last two bytes are kept
** if it is greater then the string is padded with 0s
*/

char *adjust_str(char *str, size_t x)
{
	size_t i;
	size_t adj;

	i = 0;
	adj = 0;
	if (!str)
		return (NULL);
	if (x == ft_strlen(str))
		return (str);
	if (x > ft_strlen(str))
		return (pad_string(str, x));
	adj = ft_strlen(str) - x;
	while (str[adj])
	{
		str[i] = str[adj];
		i++;
		adj++;
	}
	str[i] = '\0';
	return (str);
}