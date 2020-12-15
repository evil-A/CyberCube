/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 01:52:07 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/15 03:00:36 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	if (!(result = (char*)malloc(size * count)))
		return (NULL);
	i = 0;
	while (i < (count * size))
		result[i++] = 0;
	return (result);
}
