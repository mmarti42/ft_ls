/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 06:23:19 by abartole          #+#    #+#             */
/*   Updated: 2018/12/05 16:20:18 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	ft_putstr_fd(char const *s, int fd)
{
	unsigned int i;

	i = 0;
	if (s)
		while (s[i])
			write(fd, &s[i++], 1);
}
