/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:10:34 by tbui              #+#    #+#             */
/*   Updated: 2015/11/24 23:13:15 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		my_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = s;
	if (n < 1)
		return ;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void			*ft_memalloc(size_t size)
{
	void *memoire;

	if (size < 1)
		return (NULL);
	if (!(memoire = malloc(sizeof(void) * size)))
		return (NULL);
	my_bzero(memoire, size);
	return (memoire);
}
