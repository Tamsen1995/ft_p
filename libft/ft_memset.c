/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:37:15 by tbui              #+#    #+#             */
/*   Updated: 2015/11/30 18:32:22 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static unsigned	char	changer(int n)
{
	unsigned	char c;

	c = n;
	return (c);
}

void					*ft_memset(void *s, int c, size_t n)
{
	char		chr;
	char		*fuckall;
	size_t		i;

	fuckall = (char *)s;
	chr = changer(c);
	i = 0;
	while (i != n)
	{
		fuckall[i] = chr;
		i++;
	}
	return (s);
}
