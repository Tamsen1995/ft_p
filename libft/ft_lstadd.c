/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:01:39 by tbui              #+#    #+#             */
/*   Updated: 2017/12/08 18:26:38 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** INVALID overrides everything
** rev overrides everything in the sense that
** it cooperates with the given condition
*/

int			stack_sorting(t_stack *s1, t_stack *s2, char *flags)
{
	time_t s1_time;
	time_t s2_time;

	s1_time = s1->stats.st_mtimespec.tv_sec;
	s2_time = s2->stats.st_mtimespec.tv_sec;
	if (s1->type == INVALID && s2->type != INVALID)
		return (-1);
	if (s1->type != INVALID && s2->type == INVALID)
		return (1);
	if (flags[f_time] && s1->type != INVALID && s2->type != INVALID
	&& s1_time != s2_time)
	{
		if (flags[f_rev])
			return (s1_time - s2_time);
		return (s2_time - s1_time);
	}
	if (flags[f_rev])
		return (ft_strcmp(s2->filename, s1->filename));
	return (ft_strcmp(s1->filename, s2->filename));
}

void		ft_list_push_back(t_stack **begin_list, \
struct dirent *ent, char *path, char *flags)
{
	t_stack *cur;
	t_stack *prev;
	t_stack *new;

	new = ft_lstnew(ent, path, flags);
	cur = NULL;
	if (!*begin_list)
	{
		*begin_list = ft_lstnew(ent, path, flags);
		return ;
	}
	cur = *begin_list;
	if (stack_sorting(cur, new, flags) > 0)
	{
		new->next = cur;
		*begin_list = new;
		return ;
	}
	while (cur && stack_sorting(cur, new, flags) <= 0)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->next = cur;
}
