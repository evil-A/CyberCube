/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 04:11:56 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/25 04:12:15 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (alst)
	{
		temp = *alst;
		if (!*alst)
			*alst = new;
		else
		{
			while (temp->next != 0)
			{
				temp = temp->next;
			}
			temp->next = new;
			new->next = 0;
		}
	}
}
