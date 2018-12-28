/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_opendir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:30:12 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 17:31:30 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** a wrapper around opendir to make it safer
** in case the function fails it safely exits the programs
*/

DIR			*safe_opendir(char *dir_path)
{
	DIR		*dir;

	dir = NULL;
	if (!(dir = opendir(dir_path)))
		fatal("Could not open directory in (safe_opendir)");
	return (dir);
}
