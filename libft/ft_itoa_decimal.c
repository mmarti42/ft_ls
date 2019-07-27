/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:04:05 by abartole          #+#    #+#             */
/*   Updated: 2019/07/06 16:28:57 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_decimal(unsigned int value, unsigned int base)
{
	int				len;
	char			*s;
	unsigned int	n;

	len = 1;
	n = value;
	while ((n = n / base) >= 1)
		len++;
	if (!(s = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = '\0';
	while (value >= base)
	{
		s[--len] = "0123456789abcdef"[value % base];
		value /= base;
	}
	s[--len] = "0123456789abcdef"[value % base];
	return (s);
}
