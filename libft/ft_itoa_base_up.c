/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 20:47:16 by abartole          #+#    #+#             */
/*   Updated: 2019/07/06 16:51:09 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_up(unsigned int value, int base)
{
	char	*str;
	long	n;
	int		i;

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
		str[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n = n / base;
	}
	(i == 0) ? str[i] = '-' : 0;
	return (str);
}
