/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:12:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/19 17:38:42 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

int			is_nan(char *str)
{
	if (ft_strstr(str, "nan"))
		return (1);
	return (0);
}

int			get_lst_len(t_number *lst)
{
	int len;

	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}

void		free_num(t_number **lst)
{
	t_number *tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = 0;
}

t_number	*new_num(int num)
{
	t_number *new;

	if (!(new = (t_number *)malloc(sizeof(t_number))))
		return (0);
	new->next = 0;
	new->num = num;
	return (new);
}
