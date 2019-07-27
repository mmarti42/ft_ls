/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:44:26 by abartole          #+#    #+#             */
/*   Updated: 2019/07/16 20:45:13 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	parse_len(va_list args, t_printf *flags)
{
	if (flags->l == 1)
		return ((long)va_arg(args, uintmax_t));
	else if (flags->ll == 1)
		return ((long long)va_arg(args, uintmax_t));
	else if (flags->h == 1)
		return ((short)va_arg(args, uintmax_t));
	else if (flags->hh == 1)
		return ((signed char)va_arg(args, uintmax_t));
	else if (flags->z == 1)
		return ((size_t)va_arg(args, uintmax_t));
	else if (flags->j == 1)
		return (va_arg(args, uintmax_t));
	return (va_arg(args, int));
}

char		*precision(char *str, t_printf *flags)
{
	int		len;
	int		precision;

	if (flags->precision == 0)
		return (str);
	len = ft_strlen(str);
	len += (str[0] == '-') ? -1 : 0;
	precision = flags->precision;
	if (str[0] == '-')
		while (precision-- > len)
			str = negative_precision(str);
	else
	{
		while (precision-- > len)
		{
			str = join_zero(str);
			if (str[1] == '-')
			{
				str[1] = '0';
				str[0] = '-';
			}
		}
	}
	return (str);
}

uintmax_t	parse_unsigned_len(va_list args, t_printf *flags)
{
	if (flags->l == 1)
		return ((unsigned long)va_arg(args, uintmax_t));
	else if (flags->ll == 1)
		return ((unsigned long long)va_arg(args, uintmax_t));
	else if (flags->h == 1)
		return ((unsigned short)va_arg(args, uintmax_t));
	else if (flags->hh == 1)
		return ((unsigned char)va_arg(args, uintmax_t));
	else if (flags->z == 1)
		return ((size_t)va_arg(args, uintmax_t));
	else if (flags->j == 1)
		return (va_arg(args, uintmax_t));
	return (va_arg(args, unsigned int));
}

char		*precision_string(char *temp, t_printf *flags)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(flags->precision);
	while (flags->precision-- && temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	return (str);
}

char		*negative_precision(char *str)
{
	char	*temporary;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			str[i] = '0';
			temporary = str;
			str = ft_strjoin("-", temporary);
			free(temporary);
			break ;
		}
		i++;
	}
	return (str);
}
