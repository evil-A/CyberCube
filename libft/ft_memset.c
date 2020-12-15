/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 21:36:33 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/08 21:37:01 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	letro;
	unsigned char	*string;

	string = (unsigned char*)b;
	letro = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		string[i] = letro;
		i++;
	}
	return (string);
}
