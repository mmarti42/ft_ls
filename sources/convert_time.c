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

# define HALF_YEAR 15778463

char 	*cut_hours(char *str)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ':')
			++j;
		if (j == 2)
			str[i] = 0;
		++i;
	}
	tmp = ft_strdup(str);
	return (tmp);
}

char	*ft_strjoin_sym(char const *s1, char const *s2, char c)
{
	unsigned int	len1;
	unsigned int	len2;
	char			*str;
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2 + 2;
	if (!(str = (char *)ft_memalloc(sizeof(str) * len)))
		return (0);
	while (i < len1)
		str[i++] = *s1++;
	str[i++] = c;
	while (i < len)
		str[i++] = *s2++;
	str[len] = 0;
	return (str);
}

char 	*get_year(char **tmp)
{
	char	*ret;
	int 	i;

	i = 0;
	ret = ft_strdup(tmp[4]);
	while (ret[i] && ret[i] != '\n')
		++i;
	ret[i] = 0;
	return (ret);
}

char	*cut_date(char *year, char **tmp)
{
	char	*t;
	char	*str;
	char	*hours;

	str = ft_strdup(tmp[1]);
	str = ft_strjoin_sym(str, tmp[2], ' ');
	if (year)
	{
		t = str;
		str = ft_strjoin_sym(str, year, ' ');
		free(t);
	}
	else
	{
		t = str;
		hours = cut_hours(tmp[3]);
		str = ft_strjoin_sym(str, hours, ' ');
		free(hours);
		free(t);
	}
	return (str);
}

char	*convert_time(long t)
{
	char *str;
	long cur_time;
	char *year;
	char **tmp;

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
	str = cut_date(year, tmp);
	return (str);
}