/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:01:08 by abartole          #+#    #+#             */
/*   Updated: 2019/07/18 17:47:22 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conversion_float(va_list args, t_printf *flags)
{
	long double d;
	char		*str;

	if (flags->precision == -1)
		flags->precision = 6;
	if (flags->l || (flags->lld == 0 && flags->l == 0))
	{
		d = va_arg(args, double);
		str = double_main(d, flags);
	}
	else
	{
		d = va_arg(args, long double);
		str = double_main(d, flags);
	}
	return (str);
}

char	*conversion_percent(void)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = '%';
	return (str);
}

char	*conversion_string(va_list args, t_printf *flags)
{
	char	*str;
	char	*temp;

	if (!(temp = va_arg(args, char *)) && flags->precision != 0)
		str = return_null(flags);
	else if (flags->precision > -1)
		str = precision_string(temp, flags);
	else
		str = ft_strdup(temp);
	return (str);
}

char	*conversion_char(va_list args, t_printf *flags)
{
	char	c;
	char	*str;

	c = va_arg(args, int);
	if (!c)
	{
		flags->width--;
		flags->size++;
		if (flags->minus == 1)
		{
			ft_putchar('\0');
			flags->size--;
			flags->total++;
		}
		return (ft_strnew(1));
	}
	str = ft_strnew(1);
	str[0] = c;
	return (str);
}

char	*conversion_address(va_list args, t_printf *flags)
{
	long	address;
	char	*str;
	char	*temp;

	address = va_arg(args, long);
	if (flags->precision == 0)
		return (ft_strdup("0x"));
	if (address == 0)
	{
		temp = ft_strnew(1);
		temp[0] = '0';
	}
	else
		temp = ft_itoa_unsigned(address, 16);
	if (flags->precision > -1)
		temp = precision(temp, flags);
	str = ft_strjoin("0x", temp);
	free(temp);
	return (str);
}
