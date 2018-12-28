
#include "libft.h"
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*dest;

	dest = (char*)malloc(sizeof(char) * (size + 1));
	if (dest)
	{
		ft_bzero(dest, (size + 1));
		return (dest);
	}
	return (NULL);
}
