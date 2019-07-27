/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:23:27 by lshellie          #+#    #+#             */
/*   Updated: 2019/07/23 14:23:30 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

char		*convert_linked_file(char *path)
{
	char	*buf;

	if (!(buf = (char *)ft_memalloc(1025)))
		return (0);
	readlink(path, buf, 1024);
	return (buf);
}

char		*convert_maj(dev_t dev)
{
	char	*str;

	str = ft_itoa(major(dev));
	return (str);
}

char		*convert_min(dev_t dev)
{
	char	*str;

	str = ft_itoa(minor(dev));
	return (str);
}

char		*convert_perm(unsigned short mod)
{
	char	*str;

	str = ft_strnew(10);
	str[0] = (S_ISLNK(mod) == 1 ? 'l' : '-');
	str[0] = (S_ISBLK(mod) == 1 ? 'b' : str[0]);
	str[0] = (S_ISDIR(mod) > 0 ? 'd' : str[0]);
	str[0] = (S_ISCHR(mod) > 0 ? 'c' : str[0]);
	str[0] = (S_ISFIFO(mod) > 0 ? 'p' : str[0]);
	str[0] = (S_ISSOCK(mod) > 0 ? 's' : str[0]);
	str[1] = ((mod & S_IRUSR) > 0 ? 'r' : '-');
	str[2] = ((mod & S_IWUSR) > 0 ? 'w' : '-');
	str[3] = ((mod & S_IXUSR) > 0 ? 'x' : '-');
	str[4] = ((mod & S_IRGRP) > 0 ? 'r' : '-');
	str[5] = ((mod & S_IWGRP) > 0 ? 'w' : '-');
	str[6] = ((mod & S_IXGRP) > 0 ? 'x' : '-');
	str[7] = ((mod & S_IROTH) > 0 ? 'r' : '-');
	str[8] = ((mod & S_IWOTH) > 0 ? 'w' : '-');
	str[9] = ((mod & S_IXOTH) > 0 ? 'x' : '-');
	return (str);
}
