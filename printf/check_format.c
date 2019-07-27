/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:27:17 by abartole          #+#    #+#             */
/*   Updated: 2019/07/18 15:43:07 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_precision(char **format, va_list args, t_printf *flags)
{
	int i;

	i = 0;
	if (**format == '.')
	{
		flags->precision = 0;
		(*format)++;
	}
	if (**format == '*')
	{
		flags->precision = va_arg(args, int);
		(*format)++;
		if (flags->precision < 0)
			flags->precision = -1;
	}
	else
	{
		i = ft_atoi(*format);
		*format += count_digits(*format);
		if (i > 0)
		{
			flags->precision = i;
		}
	}
}

void	check_field_width(char **format, va_list args, t_printf *flags)
{
	int n;

	if (**format == '*')
	{
		(*format)++;
		flags->width = va_arg(args, int);
	}
	if (flags->width < -1)
	{
		flags->minus = 1;
		flags->width = -flags->width;
	}
	n = ft_atoi(*format);
	*format += count_digits(*format);
	if (n > 0)
		flags->width = n;
}

void	check_conversion(t_printf *flags)
{
	if (flags->conversion == 'D')
	{
		flags->conversion = 'd';
		flags->l = 1;
	}
	else if (flags->conversion == 'O')
	{
		flags->conversion = 'o';
		flags->l = 1;
	}
	else if (flags->conversion == 'U')
	{
		flags->conversion = 'u';
		flags->l = 1;
	}
}

int		check_specifier(char **format, t_printf *flags)
{
	if (**format != 's' && **format != 'd' && **format != 'i' &&
			**format != 'o' && **format != 'p' && **format != 'u' &&
			**format != 'x' && **format != 'X' && **format != 'c' &&
			**format != 'f' && **format != '%' && **format != 'U' &&
			**format != 'D' && **format != 'O')
		return (0);
	flags->conversion = **format;
	check_conversion(flags);
	return (1);
}

char	*check_format(char **format, va_list args, t_printf *flags)
{
	(*format)++;
	if ((!(**format) || (!(*format))))
		return (NULL);
	check_flags(format, flags);
	check_field_width(format, args, flags);
	check_precision(format, args, flags);
	check_length(format, flags);
	if (!(check_specifier(format, flags)))
		return (invalid_format(format, flags));
	return (lets_work(args, flags));
}
