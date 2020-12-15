/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 01:33:07 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/10 22:37:56 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*in;
	unsigned char	*fi;
	unsigned char	letro;

	letro = (unsigned char)c;
	fi = (unsigned char *)dst;
	in = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		fi[i] = in[i];
		if (in[i] == letro)
		{
			return (&dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
