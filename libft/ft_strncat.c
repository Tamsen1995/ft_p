/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:44:42 by tbui              #+#    #+#             */
/*   Updated: 2015/11/24 18:36:14 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && i != n)
	{
		*dest = *src;
		i++;
		src++;
		dest++;
	}
	*dest = '\0';
	return (ret);
}
