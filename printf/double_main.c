/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:28:20 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/19 17:43:33 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			is_inf(char *str)
{
	if (ft_strstr(str, "inf"))
		return (1);
	return (0);
}

static char			*plus(char *str)
{
	int		i;
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	i = 0;
	tmp = str;
	while (i < len)
	{
		if (str[i] == '-')
			return (str);
		++i;
	}
	str = ft_strjoin("+", tmp);
	free(tmp);
	return (str);
}

static char			*width(char *str, t_printf *flags)
{
	char	*tmp;
	char	*j;
	char	c;

	c = ' ';
	tmp = str;
	if (!(j = (char *)ft_memalloc(flags->width - ft_strlen(str) + 1)))
		return (0);
	if (flags->zero && !flags->minus && !is_nan(str) && !is_inf(str))
		c = '0';
	ft_memset(j, c, flags->width - ft_strlen(str));
	if (c == '0' && (str[0] == '-' || str[0] == '+' || str[0] == ' '))
	{
		j[0] = str[0];
		str[0] = c;
	}
	if (flags->minus)
		str = ft_strjoin(tmp, j);
	else
		str = ft_strjoin(j, tmp);
	free(tmp);
	free(j);
	return (str);
}

char				*space(char *str, t_printf *flags)
{
	char	*tmp;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	tmp = str;
	while (i < len)
	{
		if (str[i] == '-')
			return (str);
		++i;
	}
	if (flags->width == len)
	{
		str = ft_strjoin(" ", tmp);
		free(tmp);
	}
	else if (flags->width != len)
	{
		str = ft_strjoin(" ", tmp);
		free(tmp);
	}
	return (str);
}

char				*double_main(long double p, t_printf *flags)
{
	char	*str;
	int		nan;
	int		inf;

	str = make_double(p, flags->precision);
	nan = is_nan(str);
	inf = is_inf(str);
	if (flags->hash && !nan && !inf)
		str = make_dot(str);
	if (flags->space && !flags->plus && !is_nan(str))
		str = space(str, flags);
	if (flags->plus && !nan)
		str = plus(str);
	if (flags->width > (int)ft_strlen(str))
		str = width(str, flags);
	return (str);
}
