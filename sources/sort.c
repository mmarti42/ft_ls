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
		if (ft_strcmp(lbegin->name, lcurr->name))
			lbegin = lbegin->left;
		else
			lbegin = lbegin->right;
	}
	if (ft_strcmp(lbegin->name, lcurr->name))
		tmp->left = lcurr;
	else
		tmp->right = lcurr;
}
