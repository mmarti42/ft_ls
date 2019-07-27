/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:38:29 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/12 10:38:31 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

char			*is_nan_or_inf(long double p, char *frac)
{
	while (*frac)
	{
		++frac;
		if (*frac == '1')
			return (ft_strdup("nan"));
	}
	if (get_sign(p))
		return (ft_strdup("-inf"));
	return (ft_strdup("inf"));
}

void			set_int(char *str, t_number *integral)
{
	int len;

	len = get_lst_len(integral);
	while (integral)
	{
		str[--len] = integral->num + 48;
		integral = integral->next;
	}
}

static void		div_lst(t_number *lst)
{
	int			tmp;
	t_number	*prev;

	tmp = 0;
	while (lst)
	{
		tmp = tmp * 10 + lst->num;
		lst->num = tmp / 2;
		tmp = tmp % 2;
		prev = lst;
		lst = lst->next;
	}
	if (tmp)
		prev->next = new_num(tmp * 10 / 2);
}

static void		mul_lst(t_number *lst)
{
	int			tmp;
	t_number	*prev;

	tmp = 0;
	while (lst)
	{
		tmp += lst->num * 2;
		lst->num = tmp % 10;
		tmp = tmp / 10;
		prev = lst;
		lst = lst->next;
	}
	if (tmp)
		prev->next = new_num(tmp);
}

t_number		*ft_big_pow(int a)
{
	t_number	*lst;

	if (a >= 0)
	{
		lst = new_num(1);
		if (a == 0)
			return (lst);
		while (a--)
			mul_lst(lst);
		return (lst);
	}
	else
	{
		lst = new_num(5);
		if (a == -1)
			return (lst);
		while (a++ != -1)
			div_lst(lst);
		return (lst);
	}
	return (0);
}
