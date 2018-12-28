/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_file_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:27:01 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 17:28:13 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Takes in a directory path and a filename
** and makes a file path out of it
*/

char			*make_file_path(char *dir_path, char *filename)
{
	char		*file_path;
	int			fl_path_len;

	fl_path_len = 0;
	file_path = NULL;
	fl_path_len = ft_strlen(dir_path);
	fl_path_len = fl_path_len + ft_strlen(filename);
	fl_path_len = fl_path_len + 2;
	file_path = ft_strnew(fl_path_len);
	file_path = ft_strcat(file_path, dir_path);
	file_path = ft_strcat(file_path, "/");
	file_path = ft_strcat(file_path, filename);
	return (file_path);
}
