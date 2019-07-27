/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 21:33:58 by abartole          #+#    #+#             */
/*   Updated: 2019/07/01 21:34:02 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long value)
{
	long	n;
	char	*str;
	int		i;

	if (value == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	n = (value < 0) ? -(long)value : value;
	i = (value < 0) ? 2 : 1;
	while ((n = n / 10) >= 1)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	n = value < 0 ? -(long)value : value;
	(value < 0) ? *str = '-' : 0;
	while (n > 9)
	{
		str[--i] = n % 10 + '0';
		n = n / 10;
	}
	str[--i] = n % 10 + '0';
	return (str);
}
