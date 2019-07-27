/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:44:22 by abartole          #+#    #+#             */
/*   Updated: 2019/07/06 18:43:42 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_length2(char **format, t_printf *flags)
{
	if (**format == 'L')
	{
		flags->lld = 1;
		(*format)++;
	}
	else if (**format == 'z')
	{
		flags->z = 1;
		(*format)++;
	}
	else if (**format == 'j')
	{
		flags->j = 1;
		(*format)++;
	}
}

void	check_length(char **format, t_printf *flags)
{
	if (**format == 'h')
	{
		(*format)++;
		if (**format == 'h')
		{
			flags->hh = 1;
			(*format)++;
		}
		else
			flags->h = 1;
	}
	else if (**format == 'l')
	{
		(*format)++;
		if (**format == 'l')
		{
			flags->ll = 1;
			(*format)++;
		}
		else
			flags->l = 1;
	}
	check_length2(format, flags);
}

void	check_flags(char **format, t_printf *flags)
{
	int counter;

	counter = count_flags(*format);
	if (counter == 0)
		return ;
	while (counter-- > 0)
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == '0')
			flags->zero = 1;
		(*format)++;
	}
}
