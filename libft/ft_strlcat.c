/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:45:10 by tbui              #+#    #+#             */
/*   Updated: 2015/11/30 18:07:26 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (srclen + size);
	if (srclen < size - dstlen)
	{
		ft_memcpy(dst + dstlen, src, srclen);
		dst += dstlen + srclen;
	}
	else if (srclen >= size - dstlen)
	{
		ft_memcpy(dst + dstlen, src, size - dstlen - 1);
		dst = dst + size - 1;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
