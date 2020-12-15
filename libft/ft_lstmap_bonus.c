/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:40:01 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/25 09:55:26 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newrdo;
	t_list	*temp;
	t_list	*begin;

	if (lst)
	{
		temp = lst;
		if (!(begin = ft_lstnew(f(temp->content))))
			return (NULL);
		temp = temp->next;
		while (temp)
		{
			if (!(newrdo = ft_lstnew(f(temp->content))))
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			ft_lstadd_back(&begin, newrdo);
			temp = temp->next;
		}
		return (begin);
	}
	return (NULL);
}
