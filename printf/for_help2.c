/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_help2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:18:43 by abartole          #+#    #+#             */
/*   Updated: 2019/07/16 18:49:40 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*join_plus(char *str)
{
	char	*temporary;

	temporary = str;
	str = ft_strjoin("+", temporary);
	free(temporary);
	return (str);
}

char	*join_space(char *str)
{
	char	*temporary;

	temporary = str;
	str = ft_strjoin(" ", temporary);
	free(temporary);
	return (str);
}

char	*join_zero(char *str)
{
	char	*temporary;

	temporary = str;
	str = ft_strjoin("0", temporary);
	free(temporary);
	return (str);
}
