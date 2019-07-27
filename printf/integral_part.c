/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:05:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/10 17:29:27 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

static int			divide(t_number *lst)
{
	int tmp;

	tmp = 0;
	if (!lst->next)
	{
		tmp = lst->num % 2;
		lst->num /= 2;
		return (tmp);
	}
	tmp = divide(lst->next) * 10 + lst->num;
	lst->num = tmp / 2;
	return (tmp % 2);
}

static t_number		*div_lst(t_number *lst, int n)
{
	t_number	*new;
	t_number	*start;

	start = 0;
	new = 0;
	while (lst)
	{
		if (!start)
		{
			start = new_num(lst->num);
			new = start;
		}
		else if (new)
		{
			new->next = new_num(lst->num);
			new = new->next;
		}
		lst = lst->next;
	}
	while (n--)
		divide(start);
	return (start);
}

void				sum_tmp(t_number *lst, int tmp)
{
	t_number	*prev;

	prev = 0;
	while (lst)
	{
		tmp += lst->num;
		lst->num = tmp % 10;
		tmp = tmp / 10;
		prev = lst;
		lst = lst->next;
	}
	if (tmp && prev)
		prev->next = new_num(tmp);
}

static void			sum_lst(t_number *lst1, t_number *lst2)
{
	t_number	*prev;
	int			tmp;

	prev = 0;
	tmp = 0;
	while (lst2)
	{
		tmp += lst1->num + lst2->num;
		lst1->num = tmp % 10;
		tmp = tmp / 10;
		prev = lst1;
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	if (tmp && prev->next)
		sum_tmp(prev->next, tmp);
	else if (tmp && !lst1)
		prev->next = new_num(tmp);
}

t_number			*get_integral_part(int exp, char *frac)
{
	t_number	*lst;
	t_number	*tmp;
	t_number	*t;
	int			i;

	norme(&lst, &tmp, &i);
	if (exp >= 0)
		lst = ft_big_pow(exp);
	while (--exp >= 0 && *(++frac) && ++i)
	{
		if (*frac == '1')
		{
			if (tmp != 0)
			{
				t = tmp;
				tmp = div_lst(tmp, i);
				free_num(&t);
			}
			else
				tmp = div_lst(lst, i);
			sum_lst(lst, tmp);
			i = 0;
		}
	}
	return (lst);
}
