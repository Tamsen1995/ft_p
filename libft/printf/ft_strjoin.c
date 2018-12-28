
#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	char	*str;
	int		i;
	int		j;

	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
