/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 17:28:46 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 17:29:10 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Takes in a string and then frees it
** points it to NULL after
** if the string is NULL it does nothing
*/

void		ft_strfree(char *string)
{
	if (!string)
		return ;
	free(string);
	string = NULL;
}
