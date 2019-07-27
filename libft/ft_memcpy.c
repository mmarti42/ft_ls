/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 02:44:00 by abartole          #+#    #+#             */
/*   Updated: 2018/11/25 06:25:43 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*qwer;
	char	*tyu;

	i = 0;
	qwer = (char *)dest;
	tyu = (char *)src;
	while (n--)
	{
		qwer[i] = tyu[i];
		i++;
	}
	return (dest);
}
