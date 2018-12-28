/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 23:22:52 by tbui              #+#    #+#             */
/*   Updated: 2015/11/30 18:22:11 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char					*ft_strnew(size_t size)
{
	char *fraiche;

	if (!(fraiche = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(fraiche, size + 1);
	return (fraiche);
}
