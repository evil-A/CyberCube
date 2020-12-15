/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:29:16 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/10 22:31:10 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*in;
	unsigned char	*fi;

	if (!dst && !src)
		return (NULL);
	fi = (unsigned char *)dst;
	in = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		fi[i] = in[i];
		i++;
	}
	return (dst);
}
