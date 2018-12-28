/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:43:23 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 17:44:12 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_putstr_col(t_stack *file)
{
	char *color;

	color = GRAY;
	if (file->type == DIRECTORY)
		color = CYAN;
	else if (file->type == SYMLINK)
		color = MAGENTA;
	if (ft_strcmp(file->filename, "ft_ls") == 0)
		color = RED;
	ft_putstr(color);
	ft_putstr(file->filename);
	ft_putstr(STOP);
}
