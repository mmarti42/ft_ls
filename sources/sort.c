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

int			setflags(char *av)
{
	while (*++av)
	{
		if (*av == 'a')
			g_a = 1;
		else if (*av == 'l')
			g_l = 1;
		else if (*av == 'R')
			g_rr = 1;
		else if (*av == 'r')
			g_r = 1;
		else if (*av == 't')
			g_t = 1;
		else if (*av == 'f')
		{
			g_f = 1;
			g_a = 1;
		}
		else
			return (error(*av));
	}
	return (0);
}

void		by_time(t_obj *lbegin, t_obj *lcurr)
{
	t_obj	*tmp;

	while (lbegin)
	{
		tmp = lbegin;
		if (lcurr->time > lbegin->time)
			lbegin = lbegin->left;
		else
			lbegin = lbegin->right;
	}
	if (lcurr->time > tmp->time)
		tmp->left = lcurr;
	else
		tmp->right = lcurr;
}

void		by_name(t_obj *lbegin, t_obj *lcurr)
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

void		not_sort(t_obj *lbegin, t_obj *lcurr)
{
	while (lbegin->right)
		lbegin = lbegin->right;
	lbegin->right = lcurr;
}

void		get_pointers(void (**sort)(t_obj*, t_obj*),
		void (**show)(t_obj*, t_column*))
{
	if (g_r)
		*show = &show_objrev;
	else
		*show = &show_obj;
	if (g_t)
		*sort = &by_time;
	else
		*sort = &by_name;
	if (g_f)
	{
		*sort = &not_sort;
		*show = &show_not_sorted;
	}
}
