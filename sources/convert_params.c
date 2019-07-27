/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:25:49 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/26 13:25:50 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

char 	*convert_size(long size)
{
	char *str;

	str = ft_itoa(size);
	return (str);
}

char	*convert_gid(unsigned int gid)
{
	struct group	*tmp;
	char 			*str;

	tmp = getgrgid(gid);
	str = ft_strdup(tmp->gr_name);
	return (str);
}

char	*convert_uid(unsigned int uid)
{
	struct passwd	*tmp;
	char 			*str;

	tmp = getpwuid(uid);
	str = ft_strdup(tmp->pw_name);
	return (str);
}

char	*convert_links(int links)
{
	char *str;

	str = ft_itoa(links);
	return (str);
}