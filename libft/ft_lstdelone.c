/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:31:14 by abartole          #+#    #+#             */
/*   Updated: 2018/12/05 16:33:56 by abartole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *act;

	act = *alst;
	if (del != NULL && alst != NULL)
	{
		del((act->content), (act->content_size));
		free(*alst);
		*alst = NULL;
	}
}
