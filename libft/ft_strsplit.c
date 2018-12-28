/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:21:48 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 17:42:32 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		amt;

	if (!s || !c)
		return (0);
	i = 0;
	amt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			amt++;
		i++;
	}
	return (amt);
}

/*
** takes in an empty 2d array, the amount of words, the character
** to by which the string is supposed to be delimited,
** and the string itself
** uses this information to fill up the twod array with the
** split up string
*/

static char		**ft_line_creator(const char *s, char **arr, char c, int amts)
{
	int		i;
	int		k;
	size_t	debut;
	size_t	longeur;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c && amts-- > 0)
		{
			debut = i;
			longeur = 0;
			while (s[i] != '\0' && s[i] != c)
			{
				i++;
				longeur++;
			}
			arr[k] = ft_strsub(s, debut, longeur);
			k++;
		}
		if (s[i])
			i++;
	}
	return (arr);
}

char			**ft_strsplit(const char *s, char c)
{
	int		amt;
	char	**arr;

	amt = 0;
	arr = NULL;
	if (!s)
		return (NULL);
	amt = ft_count_words(s, c);
	if (amt <= 0)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (amt + 1))))
		return (NULL);
	arr = ft_line_creator(s, arr, c, amt);
	arr[amt] = NULL;
	return (arr);
}
