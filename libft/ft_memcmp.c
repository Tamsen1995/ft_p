/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 22:42:21 by tbui              #+#    #+#             */
/*   Updated: 2015/11/30 18:30:35 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*p1;
	unsigned char		*p2;
	size_t				i;

	i = 1;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (*p1 == *p2 && i < n)
	{
		p1++;
		p2++;
		i++;
	}
	return (*p1 - *p2);
}
