/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:38:49 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/12 10:38:52 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

static char		*make_integral(t_number *integral, int sign)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) *
			(1 + sign + get_lst_len(integral)))))
		return (0);
	if (sign)
		str[i++] = '-';
	set_int(&str[i], integral);
	i += get_lst_len(integral);
	str[i] = 0;
	return (str);
}

static char		*make_str(t_number *integral, t_number *fractional, int sign)
{
	char	*str;
	int		i;

	if (!fractional)
		return (make_integral(integral, sign));
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) *
			(2 + sign + get_lst_len(integral) + get_lst_len(fractional)))))
		return (0);
	if (sign)
		str[i++] = '-';
	set_int(&str[i], integral);
	i += get_lst_len(integral);
	str[i++] = '.';
	while (fractional)
	{
		str[i++] = fractional->num + 48;
		fractional = fractional->next;
	}
	str[i] = 0;
	return (str);
}

static int		frac_rounding(t_number *fractional, unsigned int precision)
{
	int tmp;

	tmp = 0;
	if (!fractional->next)
		fractional->next = new_num(0);
	if (precision == 1)
	{
		fractional->num += fractional->next->num >= 5 ? 1 : 0;
		if ((tmp = fractional->num / 10))
			fractional->num %= 10;
		free_num(&fractional->next);
		return (tmp);
	}
	tmp = frac_rounding(fractional->next, --precision);
	if (tmp)
		fractional->num += tmp;
	if (fractional->num / 10)
	{
		fractional->num %= 10;
		return (1);
	}
	return (0);
}

static void		number_rounding(t_number *integral,
		t_number **fractional, unsigned int precision)
{
	int tmp;

	tmp = 0;
	if (!precision)
	{
		if ((*fractional)->next != 0)
			tmp = (*fractional)->num >= 5 ? 1 : 0;
		else if ((*fractional)->next == 0 &&
		(*fractional)->num == 5 && integral->num % 2 != 0)
		{
			++integral->num;
			sum_tmp(integral->next, integral->num / 10);
		}
		(*fractional)->num = 0;
		free_num(fractional);
	}
	else
		tmp = frac_rounding(*fractional, precision);
	sum_tmp(integral, tmp);
}

char			*make_double(long double p, unsigned int precision)
{
	char		*frac;
	int			exp;
	char		*str;
	t_number	*integral;
	t_number	*fractional;

	frac = get_frac(p);
	exp = get_exp(p);
	if (exp == 16384)
		return (is_nan_or_inf(p, frac));
	integral = get_integral_part(exp, frac);
	integral = (!integral ? new_num(0) : integral);
	fractional = get_fractional_part(exp, frac);
	fractional = (!fractional ? new_num(0) : fractional);
	number_rounding(integral, &fractional, precision);
	str = make_str(integral, fractional, get_sign(p));
	if (fractional)
		free_num(&fractional);
	free_num(&integral);
	return (str);
}
