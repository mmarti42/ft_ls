/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:25:32 by abartole          #+#    #+#             */
/*   Updated: 2019/07/16 18:28:15 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*do_space_int(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	if (str[i] != '-' && str[i] != ' ' && str[i + 1] != ' ')
	{
		temp = str;
		str = ft_strjoin(" ", temp);
		free(temp);
	}
	return (str);
}

char	*do_zero_int(char *str, t_printf *flags)
{
	int i;

	i = 0;
	if (flags->space == 1)
		if (str[0] == ' ')
			i++;
	while (str[i])
	{
		if (str[i] == ' ')
			str[i] = '0';
		i++;
	}
	i = 0;
	while (str[i] && (str[i] != '-' && str[i] != '+'))
		i++;
	if ((str[0] == '0' || str[0] == ' ') && (str[i] == '-' || str[i] == '+'))
	{
		ft_swap_char(&str[0], &str[i]);
		if (str[i] == ' ')
			str[i] = '0';
	}
	return (str);
}
