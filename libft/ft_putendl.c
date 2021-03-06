/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:44:08 by abartole          #+#    #+#             */
/*   Updated: 2018/12/05 19:32:15 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	unsigned int i;

	i = 0;
	if (s)
	{
		while (s[i])
			write(1, &s[i++], 1);
	}
	write(1, "\n", 1);
}
