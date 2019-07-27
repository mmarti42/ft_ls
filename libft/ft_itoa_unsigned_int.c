/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:36:40 by abartole          #+#    #+#             */
/*   Updated: 2019/06/25 17:42:28 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unsigned_int(unsigned int value)
{
	char			*str;
	unsigned int	n;
	int				i;

	n = value;
	i = 1;
	while ((n = n / 10) >= 1)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	n = value;
	while (i--)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}
