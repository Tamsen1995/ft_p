/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 22:10:42 by tbui              #+#    #+#             */
/*   Updated: 2015/11/30 18:31:57 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*temp;
	int				index;
	int				limit;

	limit = len;
	index = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	temp = (unsigned char *)malloc(len);
	while (len--)
	{
		temp[index] = s2[index];
		index++;
	}
	index = 0;
	while (index < limit)
	{
		s1[index] = temp[index];
		index++;
	}
	return ((unsigned char *)dst);
}
