/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:08:39 by abartole          #+#    #+#             */
/*   Updated: 2019/07/16 17:17:04 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_flags(t_printf *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->precision = -1;
	flags->width = -1;
	flags->size = 0;
	flags->conversion = 0;
	flags->h = 0;
	flags->hh = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->lld = 0;
	flags->z = 0;
	flags->j = 0;
}

int		print_format(char **format, va_list args, t_printf *flags)
{
	char	*str;

	if (!(str = check_format(format, args, flags)))
		return (0);
	flags->size += ft_strlen(str);
	write(1, str, flags->size);
	if (str)
		free(str);
	flags->total += flags->size;
	return (1);
}

int		read_format(char **format, va_list args)
{
	t_printf	flags;

	flags.total = 0;
	while (**format)
	{
		initialize_flags(&flags);
		if (**format == '%')
		{
			if (!(print_format(format, args, &flags)))
				return (flags.total);
		}
		else
		{
			write(1, *format, 1);
			flags.total++;
		}
		(*format)++;
	}
	return (flags.total);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		printed;

	if (!format || !*format)
		return (0);
	va_start(args, format);
	printed = read_format((char **)&format, args);
	va_end(args);
	return (printed);
}
