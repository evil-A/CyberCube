/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 03:58:24 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/10 18:48:02 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	letro;
	size_t			i;

	i = 0;
	string = (unsigned char *)s;
	letro = (unsigned char)c;
	while (n > 0)
	{
		if (string[i] == letro)
		{
			return (&string[i]);
		}
		n--;
		i++;
	}
	return (NULL);
}
