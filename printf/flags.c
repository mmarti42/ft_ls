/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:12:58 by abartole          #+#    #+#             */
/*   Updated: 2019/07/18 15:36:18 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*do_hash(char *str, t_printf *flags)
{
	char	*temp;
	int		len;

	len = ft_strlen(str);
	if (flags->hash == 1 && *str != '\0')
	{
		if (flags->conversion == 'o' && str[0] != '0')
		{
			temp = str;
			str = ft_strjoin("0", temp);
			free(temp);
		}
		if ((flags->conversion == 'x' || flags->conversion == 'X') && str[0])
			str = do_hash_for_x(str, flags);
	}
	return (str);
}

char	*do_space(char *str, t_printf *flags)
{
	int		len;

	if (flags->plus == 1)
		return (str);
	len = ft_strlen(str);
	if (flags->conversion == 'f' && str[0] != '-')
	{
		if (flags->plus == 0 && (flags->width == -1 ||
				flags->width > len))
			str = join_space(str);
		else if (flags->zero == 1 && flags->minus == 0 &&
				(!(ft_isdigit(str[0])) || (str[0] == '0' &&
									len == flags->width)))
			str[0] = ' ';
		else if (flags->zero == 0 && flags->minus == 1)
			str = join_space(str);
		else if (flags->plus == 0 && (!(len == flags->width &&
						(str[0] == ' ' || str[0] == '+' || str[0] == '0'))))
			str = join_space(str);
	}
	return (str);
}

char	*do_zero(char *str, t_printf *flags)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (flags->precision == 0)
		return (str);
	if (flags->minus == 0 && (flags->precision == -1 || flags->precision == 0 ||
				flags->precision > flags->width))
	{
		while (str[i])
		{
			if (str[i] == ' ')
				str[i] = '0';
			i++;
		}
	}
	if (flags->hash == 1 && (flags->conversion == 'x' ||
				flags->conversion == 'X'))
		return (do_hash_zero(str, flags));
	if (flags->plus == 1 && (flags->conversion == 'd' ||
				flags->conversion == 'i' || flags->conversion == 'f'))
		str = do_zero_plus(str, flags, len);
	return (str);
}

char	*do_plus(char *str, t_printf *flags)
{
	char	*temp;
	int		i;

	i = 0;
	if (str[i] != '-')
	{
		if (flags->plus == 1)
		{
			temp = str;
			str = ft_strjoin("+", temp);
			free(temp);
		}
	}
	return (str);
}

char	*do_width(char *str, t_printf *flags)
{
	char	*temporary;
	int		len;
	int		width;

	width = flags->width;
	len = ft_strlen(str);
	if (width == 0 && *str == '0' && flags->precision == -1)
		return (ft_strnew(0));
	while (width-- > len)
	{
		temporary = str;
		if (flags->minus == 1)
			str = ft_strjoin(temporary, " ");
		else
			str = ft_strjoin(" ", temporary);
		free(temporary);
	}
	return (str);
}
