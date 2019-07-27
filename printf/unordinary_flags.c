/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unordinary_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:43:34 by abartole          #+#    #+#             */
/*   Updated: 2019/07/16 18:52:39 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*do_zero_plus_int(char *str, t_printf *flags)
{
	int		i;

	i = 0;
	(void)flags;
	while (str[i])
	{
		if (str[i] == ' ')
			str[i] = '0';
		i++;
	}
	i = 0;
	while (str[i] != '-' || str[i] != '+')
		i++;
	if (str[i] == '\0')
		str = join_plus(str);
	else
	{
		i--;
		if (str[i] == '-')
			str[0] = '-';
		else if (str[i] == '+')
			str[0] = '+';
		str[i] = '0';
	}
	return (str);
}

char	*do_zero_plus(char *str, t_printf *flags, int len)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == '-')
			break ;
	if (str[i] == '\0')
	{
		if ((flags->precision < flags->width) && flags->precision != -1 &&
				(str[0] == '0' || str[0] == ' '))
		{
			while (str[j] == ' ')
				j++;
			j--;
			str[j] = '+';
		}
		else if (flags->width == len && str[0] == '0')
			str[0] = '+';
		else if (str[0] != '+')
			str = join_plus(str);
	}
	flags->plus = 0;
	return (str);
}

char	*do_hash_zero(char *str, t_printf *flags)
{
	int i;

	i = 0;
	if (str[i] == '0')
	{
		while (str[i] == '0')
		{
			if (str[i] == 'x' || str[i] == 'X')
			{
				str[i] = '0';
				break ;
			}
			if (str[i] == '\0')
				return (str);
			i++;
		}
	}
	if (str[i] == '\0' || str[i] == 'x' || str[i] == 'X')
		str = add_for_x(str, flags, i);
	return (str);
}

char	*do_hash_for_x(char *str, t_printf *flags)
{
	char	*temporary;

	if (flags->conversion == 'x')
	{
		temporary = str;
		str = ft_strjoin("0x", temporary);
		free(temporary);
	}
	else
	{
		temporary = str;
		str = ft_strjoin("0X", temporary);
		free(temporary);
	}
	return (str);
}

char	*add_for_x(char *str, t_printf *flags, int i)
{
	if (flags->conversion == 'x')
	{
		str[i] = '0';
		str[1] = 'x';
	}
	else if (flags->conversion == 'X')
	{
		str[i] = '0';
		str[1] = 'X';
	}
	return (str);
}
