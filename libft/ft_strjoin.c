/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:08:02 by tbui              #+#    #+#             */
/*   Updated: 2015/11/25 18:09:19 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	my_strlen(const char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	char	*conc;
	int		mem;

	if (!s1 || !s2)
		return (NULL);
	mem = my_strlen(s1) + my_strlen(s2);
	if (!(conc = (char *)malloc(sizeof(char) * mem + 1)))
		return (NULL);
	tmp = conc;
	while (*s1 != '\0')
	{
		*tmp = *s1;
		tmp++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*tmp = *s2;
		tmp++;
		s2++;
	}
	*tmp = '\0';
	return (conc);
}
