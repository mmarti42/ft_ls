/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:36:18 by abartole          #+#    #+#             */
/*   Updated: 2019/07/19 18:01:06 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*invalid_format(char **format, t_printf *flags)
{
	(void)format;
	(void)flags;

	return (0);
}

char	*flags_for_int(char *str, t_printf *flags)
{
	if (flags->precision > -1)
	{
		flags->zero = 0;
		if (flags->width > -1)
			flags_for_int1(&str, &flags);
		else if (flags->plus == 1)
		{
			flags->space = 0;
			str = do_plus(str, flags);
		}
		else if (flags->space == 1)
			str = do_space_int(str);
	}
	else if (flags->precision == -1)
	{
		if (flags->width == -1)
			flags_for_int4(&str, &flags);
		else
			flags_for_int3(&str, &flags);
	}
	return (str);
}

char	*do_flag(char *str, t_printf *flags)
{
	if (flags->conversion == 'd' || flags->conversion == 'i')
		str = flags_for_int(str, flags);
	else if (flags->conversion == 'f')
		return (str);
	else
	{
		str = do_hash(str, flags);
		if (flags->plus == 1 && flags->conversion != 'u')
			str = do_plus(str, flags);
		str = do_width(str, flags);
		if (flags->zero == 1)
		{
			str = do_zero(str, flags);
			str = work_with_negative(str);
		}
		if (flags->space == 1)
			str = do_space(str, flags);
	}
	if (!str)
		return (NULL);
	return (str);
}

char	*do_conversion(va_list args, t_printf *flags)
{
	if (flags->conversion == 'p')
		return (conversion_address(args, flags));
	else if (flags->conversion == 'c')
		return (conversion_char(args, flags));
	else if (flags->conversion == 's' || flags->conversion == 'S')
		return (conversion_string(args, flags));
	else if (flags->conversion == 'd' || flags->conversion == 'i')
		return (conversion_int(args, flags));
	else if (flags->conversion == 'o')
		return (conversion_octal(args, flags));
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		return (conversion_hex(args, flags));
	else if (flags->conversion == 'u' || flags->conversion == 'U')
		return (conversion_decimal(args, flags));
	else if (flags->conversion == '%')
		return (conversion_percent());
	else if (flags->conversion == 'f')
		return (conversion_float(args, flags));
	return (0);
}

char	*lets_work(va_list args, t_printf *flags)
{
	char *str;

	str = do_conversion(args, flags);
	str = do_flag(str, flags);
	return (str);
}
