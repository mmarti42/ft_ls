/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 06:11:32 by mmarti            #+#    #+#             */
/*   Updated: 2019/07/04 06:11:34 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

int setFlags(char *av)
{
	while (*++av)
	{
		if (*av != 'a' && *av != 'l' && *av != 'R' && *av != 'r' && *av != 't')
			return (error(*av));
		if (*av == 'a')
			a = 1;
		else if (*av == 'l')
			l = 1;
		else if (*av == 'R')
			R = 1;
		else if (*av == 'r')
			r = 1;
		else if (*av == 't')
			t = 1;
	}
	return (0);
}

void	by_time(t_obj *lbegin, t_obj* lcurr)
{
	t_obj *tmp;

	while (lbegin)
	{
		tmp = lbegin;
		if (lcurr->time < lbegin->time)
			lbegin = lbegin->left;
		else
			lbegin = lbegin->right;
	}
	if (lcurr->time < tmp->time)
		tmp->left = lcurr;
	else
		tmp->right = lcurr;
}

void	by_name(t_obj *lbegin, t_obj* lcurr)
{
	t_obj *tmp;

	while (lbegin)
	{
		tmp = lbegin;
		if (ft_strcmp(lbegin->name, lcurr->name) > 0)
			lbegin = lbegin->left;
		else
			lbegin = lbegin->right;
	}
	if (ft_strcmp(tmp->name, lcurr->name) > 0)
		tmp->left = lcurr;
	else
		tmp->right = lcurr;
}
