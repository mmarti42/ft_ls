/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:39:25 by abartole          #+#    #+#             */
/*   Updated: 2019/07/16 17:16:08 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conversion_hex(va_list args, t_printf *flags)
{
	uintmax_t	hex;
	char		*str;

	hex = parse_unsigned_len(args, flags);
	if (hex == 0)
		flags->hash = 0;
	if (flags->precision == 0 && hex == 0)
		return (ft_strnew(0));
	if (flags->l == 1 || flags->ll == 1 || flags->z == 1 || flags->j == 1)
		str = ft_itoa_unsigned_long(hex, 16);
	else
		str = ft_itoa_unsigned_long(hex, 16);
	if (flags->conversion == 'X')
		make_up(str);
	if (flags->precision > -1)
		str = precision(str, flags);
	return (str);
}

char	*conversion_octal(va_list args, t_printf *flags)
{
	uintmax_t	octal;
	char		*str;

	octal = parse_unsigned_len(args, flags);
	if (flags->precision == 0 && octal == 0 && flags->hash == 0)
		return (ft_strnew(0));
	else if (flags->precision == 0 && octal == 0 && flags->hash == 1)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	if (flags->l == 1 || flags->ll == 1 || flags->z == 1 || flags->j == 1)
		str = ft_itoa_unsigned_long(octal, 8);
	else
		str = ft_itoa_decimal(octal, 8);
	if (flags->precision > -1)
		str = precision(str, flags);
	return (str);
}

char	*conversion_int(va_list args, t_printf *flags)
{
	intmax_t	i;
	char		*str;

	i = parse_len(args, flags);
	if (flags->precision == 0 && i == 0)
		return (ft_strnew(0));
	if (flags->l == 1 || flags->ll == 1 || flags->z == 1 || flags->j == 1)
		str = ft_ltoa(i);
	else
		str = ft_itoa(i);
	if (flags->precision > -1)
		str = precision(str, flags);
	return (str);
}

char	*conversion_decimal(va_list args, t_printf *flags)
{
	uintmax_t	u;
	char		*str;

	u = parse_unsigned_len(args, flags);
	if (flags->precision == 0 && u == 0)
		return (ft_strnew(0));
	if (flags->l == 1 || flags->ll == 1 || flags->z == 1 || flags->j == 1)
		str = ft_itoa_unsigned_long(u, 10);
	else
		str = ft_itoa_decimal(u, 10);
	if (flags->precision > -1)
		str = precision(str, flags);
	return (str);
}
