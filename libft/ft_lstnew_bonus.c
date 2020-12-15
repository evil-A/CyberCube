/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 06:59:39 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/25 08:52:47 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newrdo;

	if (!(newrdo = malloc(sizeof(t_list))))
		return (NULL);
	newrdo->next = NULL;
	newrdo->content = (void *)content;
	return (newrdo);
}
