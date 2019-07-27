/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 05:30:05 by abartole          #+#    #+#             */
/*   Updated: 2018/12/05 21:45:59 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char		*ft_strrev(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
		i++;
	j = 0;
	while (j < i / 2)
	{
		swap(str + j, str + i - 1 - j);
		j++;
	}
	return (str);
}
