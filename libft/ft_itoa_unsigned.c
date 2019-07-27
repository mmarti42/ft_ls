/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:36:40 by abartole          #+#    #+#             */
/*   Updated: 2019/06/29 19:10:13 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unsigned(long value, int base)
{
	char	*str;
	long	n;
	long	i;

	n = value;
	i = 1;
	while ((n = n / base) >= 1)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	n = value;
	while (i--)
	{
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n = n / base;
	}
	return (str);
}
