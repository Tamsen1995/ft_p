/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:48:35 by tbui              #+#    #+#             */
/*   Updated: 2015/11/24 14:50:47 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void					*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*src_cpy;
	unsigned char		*dst_cpy;

	src_cpy = (unsigned char *)src;
	dst_cpy = (unsigned char *)dest;
	i = 0;
	while (i < size)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	dst_cpy[i] = '\0';
	return (dst_cpy);
}