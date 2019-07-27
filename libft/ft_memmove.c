/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:35:22 by abartole          #+#    #+#             */
/*   Updated: 2018/12/05 23:47:36 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*idst;
	unsigned char	*isrc;
	size_t			i;

	i = -1;
	idst = (unsigned char *)dst;
	isrc = (unsigned char *)src;
	if (isrc < idst)
		while (len-- > 0)
			idst[len] = isrc[len];
	else
		while (++i < len)
			idst[i] = isrc[i];
	return (idst);
}
