/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_help1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:37:25 by abartole          #+#    #+#             */
/*   Updated: 2019/07/15 20:50:12 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_up(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
}

char	*work_with_negative(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && (str[i - 2] != ' ' || str[i - 1] != ' '))
		{
			str[i] = '0';
			str[0] = '-';
			break ;
		}
		i++;
	}
	return (str);
}

int		count_flags(char *str)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == '#' ||
			str[i] == '0' || str[i] == ' ')
		i++;
	return (i);
}

int		count_digits(char *str)
{
	int i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

char	*return_null(t_printf *flags)
{
	char	*null;
	char	*str;
	int		i;

	i = 0;
	null = "(null)";
	if (flags->precision > 0 && flags->precision < 6)
	{
		str = ft_strnew(flags->precision);
		while (flags->precision--)
		{
			str[i] = null[i];
			i++;
		}
	}
	else
		str = ft_strdup("(null)");
	return (str);
}
