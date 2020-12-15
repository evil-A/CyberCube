/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 04:55:09 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/25 05:33:32 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst)
	{
		while ((*lst)->next != 0)
		{
			temp = *lst;
			*lst = (*lst)->next;
			ft_lstdelone(temp, del);
		}
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
