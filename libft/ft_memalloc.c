/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:45:29 by abartole          #+#    #+#             */
/*   Updated: 2018/11/29 21:02:32 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char *temp;

	temp = NULL;
	if (!(temp = (unsigned char *)malloc(size)))
		return (NULL);
	while (size)
		temp[--size] = 0;
	return ((void *)temp);
}
