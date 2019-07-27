/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:36:40 by abartole          #+#    #+#             */
/*   Updated: 2019/07/06 16:26:18 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unsigned_long(unsigned long value, int base)
{
	char			*str;
	unsigned long	n;
	long			i;

	n = value;
	i = 1;
	while ((n = n / base) >= 1)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (value >= (unsigned)base)
	{
		str[--i] = "0123456789abcdef"[value % base];
		value /= base;
	}
	str[--i] = "0123456789abcdef"[value % base];
	return (str);
}
