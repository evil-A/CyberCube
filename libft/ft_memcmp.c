/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 02:41:52 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/11 02:56:02 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*z1;
	unsigned char	*z2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	z1 = (unsigned char*)s1;
	z2 = (unsigned char*)s2;
	while (z1[i] == z2[i] && (i < n - 1))
	{
		i++;
	}
	return ((unsigned char)z1[i] - (unsigned char)z2[i]);
}
