/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 05:10:00 by abartole          #+#    #+#             */
/*   Updated: 2018/12/05 22:12:53 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*riu;
	unsigned char	*tuk;

	i = 0;
	riu = (unsigned char *)dest;
	tuk = (unsigned char *)src;
	while (n--)
	{
		riu[i] = tuk[i];
		if (tuk[i] == (unsigned char)c)
		{
			return (&riu[i + 1]);
		}
		i++;
	}
	return (NULL);
}
