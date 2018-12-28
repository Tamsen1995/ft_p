/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:26:19 by tbui              #+#    #+#             */
/*   Updated: 2015/11/25 19:27:30 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	void	my_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putendl(char const *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		my_putchar(s[i]);
		i++;
	}
	my_putchar('\n');
}
