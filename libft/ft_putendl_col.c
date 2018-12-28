/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:01:41 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 18:03:06 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_putendl_col(t_stack *file)
{
	char *color;

	color = GRAY;
	if (file->type == DIRECTORY)
		color = CYAN;
	else if (file->type == SYMLINK)
		color = MAGENTA;
	else if (file->type == SOCK_LINK)
		color = GREEN;
	ft_putstr(color);
	ft_putstr(file->filename);
	ft_putstr(STOP);
	ft_putchar('\n');
}
