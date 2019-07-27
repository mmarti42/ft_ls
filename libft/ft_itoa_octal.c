/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:12:41 by abartole          #+#    #+#             */
/*   Updated: 2019/07/06 16:27:22 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_octal(unsigned int value, int base)
{
	unsigned int	n;
	char			*str;
	int				i;

	i = 1;
	n = value;
	while ((n = n / base) >= (unsigned)base)
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
