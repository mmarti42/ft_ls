/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:39:28 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/27 16:39:30 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

t_column		*new_column(void)
{
	t_column	*new;

	if (!(new = (t_column *)ft_memalloc(sizeof(t_column))))
		return (new);
	return (new);
}

void			set_columns(t_obj *lst, t_column *col)
{
	int len;

	if ((len = ft_strlen(lst->links)) > col->links)
		col->links = len;
	if ((len = ft_strlen(lst->master)) > col->master)
		col->master = len;
	if ((len = ft_strlen(lst->group)) > col->group)
		col->group = len;
	if ((len = ft_strlen(lst->maj)) > col->maj)
		col->maj = len;
	if ((len = ft_strlen(lst->min)) > col->min)
		col->min = len;
	if ((len = ft_strlen(lst->size)) > col->size)
		col->size = len;
	if ((len = col->maj + col->min) > col->size)
		col->size = len + 2;
	if ((len = ft_strlen(lst->time_year)) > col->time_year)
		col->time_year = len;
	if ((len = ft_strlen(lst->time_day)) > col->time_day)
		col->time_day = len;
	if ((len = ft_strlen(lst->name)) > col->name)
		col->name = len;
	col->total += lst->blocks;
}
