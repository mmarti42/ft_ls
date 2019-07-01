/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:42:08 by lshellie          #+#    #+#             */
/*   Updated: 2019/06/11 11:42:09 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_ls.h"

static void		set_flags(char c, t_flags *flags)
{
	if (c == 'R')
		flags->R = 1;
	else if (c == 'a')
		flags->a = 1;
	else if (c == 'l')
		flags->l = 1;
	else if (c == 'r')
		flags->r = 1;
	else if (c == 't')
		flags->t = 1;
}

static int		get_flags(char *str, t_flags *flags)
{
	while (*str)
	{
		if (*str != 'R' && *str != 'a'
			&& *str != 'l' && *str != 'r' && *str != 't')
		{
			ft_putstr("ft_ls : illegal option -- ");
			ft_putchar(*str);
			ft_putstr("\n usage: ls [-Ralrt] [file ...]\n");
			return (0);
		}
		else
			set_flags(*str, flags);
		++str;
	}
	return (1);
}

int				set_options(char **argv, t_flags *flags)
{
	int				i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i])
			return (0);
		if (argv[i][0] == '-' && argv[i][1] != 0)
			if (!(get_flags(&argv[i][1], flags)))
				return (-1);
		++i;
	}
	return (0);
}

int				ft_ls_main(int dir, char **argv, t_flags *flags)
{
	t_obj *lst = 0;

	if (flags->R && flags->a)
		lst = search(dir, argv, flags);
	else if (!flags->a)
		lst = search(dir, argv, flags);
	show_obj(lst, flags);
	free_obj(lst);
	return (0);
}