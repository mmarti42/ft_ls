/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:47:41 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/18 17:31:18 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

char				*make_dot(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (str);
		if (str[i] == '.')
			return (str);
		++i;
	}
	tmp = str;
	str = ft_strjoin(str, ".");
	free(tmp);
	return (str);
}

static char			*make_frac_str(long double num)
{
	unsigned char	*a;
	int				i;
	char			*str;
	int				j;
	int				k;

	i = LONG_DOUBLE;
	a = (unsigned char *)&num;
	if (!(str = (char *)malloc(LONG_DOUBLE * 8 + 1)))
		return (0);
	k = 0;
	while (--i >= 0)
	{
		j = 8;
		while (--j >= 0)
		{
			if (a[i] & (1 << j))
				str[k++] = '1';
			else
				str[k++] = '0';
		}
	}
	str[k] = 0;
	return (str);
}

char				*get_frac(long double num)
{
	char *bin;
	char *frac;

	bin = make_frac_str(num);
	frac = ft_strdup(&bin[16]);
	free(bin);
	return (frac);
}

int					get_sign(long double sign)
{
	unsigned char		*a;
	int					i;

	a = (unsigned char *)&sign;
	i = LONG_DOUBLE - 1;
	return (a[i] & (1 << 7));
}

int					get_exp(long double exp)
{
	unsigned char	*a;
	int				exp_i;
	int				res_i;
	int				res;

	a = (unsigned char *)&exp;
	res = 0;
	res_i = 14;
	exp_i = 6;
	while (exp_i >= 0)
	{
		if (a[9] & (1 << exp_i))
			res ^= (1 << res_i);
		--exp_i;
		--res_i;
	}
	exp_i = 7;
	while (exp_i >= 0)
	{
		if (a[8] & (1 << exp_i))
			res ^= (1 << res_i);
		--exp_i;
		--res_i;
	}
	return (res - 16383);
}
