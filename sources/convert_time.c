/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:53:19 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/24 14:53:21 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

#define HALF_YEAR 15778463

void		ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
}

char		*convert_month(long t)
{
	char	*str;
	char	**tmp;
	char	*ttime;

	ttime = ctime(&t);
	tmp = ft_strsplit(ttime, ' ');
	str = ft_strdup(tmp[1]);
	ft_free(tmp);
	return (str);
}

char		*convert_day(long t)
{
	char	*str;
	char	**tmp;
	char	*ttime;

	ttime = ctime(&t);
	tmp = ft_strsplit(ttime, ' ');
	str = ft_strdup(tmp[2]);
	ft_free(tmp);
	return (str);
}

char		*get_year(char **tmp)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strdup(tmp[4]);
	while (ret[i] && ret[i] != '\n')
		++i;
	ret[i] = 0;
	return (ret);
}

char		*convert_year(long t)
{
	char *str;
	long cur_time;
	char **tmp;
	char *year;

	year = 0;
	tmp = ft_strsplit(ctime(&t), ' ');
	cur_time = time(0);
	if (t > cur_time)
	{
		if ((t - cur_time) > HALF_YEAR)
			year = get_year(tmp);
	}
	else
	{
		if (cur_time - t > HALF_YEAR)
			year = get_year(tmp);
	}
	if (!year)
		str = cut_noyear(tmp[3]);
	else
		str = year;
	ft_free(tmp);
	return (str);
}
