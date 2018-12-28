
#include "libftprintf.h"

char		*ft_strdup(const char *s1)
{
	char	*copy;
	int		length;
	int		i;

	length = 0;
	while (s1[length] != '\0')
		length++;
	copy = (char*)malloc(sizeof(*s1) * (length + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i <= length)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}
