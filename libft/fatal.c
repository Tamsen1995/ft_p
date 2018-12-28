/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 19:36:11 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 19:50:46 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** a function which will print
** an error msg and then exit the program
*/

void	fatal(char *err_msg)
{
	ft_putendl(err_msg);
	exit(-1);
}
