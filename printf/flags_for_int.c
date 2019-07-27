/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_for_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:11:41 by abartole          #+#    #+#             */
/*   Updated: 2019/07/18 15:36:21 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_for_int1(char **str, t_printf **flags)
{
	if ((*flags)->plus == 1)
	{
		(*flags)->space = 0;
		if ((*flags)->minus == 1)
			(*flags)->zero = 0;
		*str = do_plus(*str, *flags);
		*str = do_width(*str, *flags);
	}
	else if ((*flags)->space == 1)
	{
		if ((*flags)->minus == 1)
		{
			*str = do_space_int(*str);
			*str = do_width(*str, *flags);
		}
		else
		{
			*str = do_width(*str, *flags);
			*str = do_space_int(*str);
		}
	}
	else
		*str = do_width(*str, *flags);
}

void	flags_for_int2(char **str, t_printf **flags)
{
	int	len;

	(*flags)->space = 0;
	if ((*flags)->minus == 1)
	{
		(*flags)->zero = 0;
		*str = do_plus(*str, *flags);
		*str = do_width(*str, *flags);
	}
	else if ((*flags)->zero == 1)
	{
		*str = do_plus(*str, *flags);
		*str = do_width(*str, *flags);
		*str = do_zero_int(*str, *flags);
		len = ft_strlen(*str);
	}
	else
	{
		*str = do_plus(*str, *flags);
		*str = do_width(*str, *flags);
	}
}

void	flags_for_int3(char **str, t_printf **flags)
{
	if ((*flags)->plus == 1)
		flags_for_int2(&*str, &*flags);
	else if ((*flags)->zero == 1)
	{
		*str = do_width(*str, *flags);
		if ((*flags)->minus == 0)
			*str = do_zero_int(*str, *flags);
		if ((*flags)->space == 1)
			*str = do_space_int(*str);
	}
	else if ((*flags)->space == 1)
	{
		*str = do_space_int(*str);
		*str = do_width(*str, *flags);
	}
	else
		*str = do_width(*str, *flags);
}

void	flags_for_int4(char **str, t_printf **flags)
{
	if ((*flags)->plus == 1)
	{
		(*flags)->space = 0;
		*str = do_plus(*str, *flags);
	}
	else if ((*flags)->space == 1)
		*str = do_space_int(*str);
}
