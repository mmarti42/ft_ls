/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:13:04 by abartole          #+#    #+#             */
/*   Updated: 2018/12/05 22:22:28 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] && (i < len))
	{
		while (s2[j] && (s1[i + j] == s2[j]) && ((i + j) < len))
			j++;
		if (!s2[j])
			return ((char *)&s1[i]);
		i++;
		j = 0;
	}
	if (!s2[0])
		return ((char *)&s1[i]);
	return (NULL);
}
