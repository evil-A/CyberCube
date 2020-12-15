/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:28:24 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/11 01:39:29 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*in;
	unsigned char	*fi;

	if (!dst && !src)
		return (dst);
	fi = (unsigned char *)dst;
	in = (unsigned char *)src;
	i = 0;
	if (in < fi)
		while ((int)--len >= 0)
			fi[len] = in[len];
	else
		while (i < len)
		{
			fi[i] = in[i];
			i++;
		}
	return (dst);
}
