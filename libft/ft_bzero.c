/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:52:06 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/09 19:53:41 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	letro;
	unsigned char	*string;

	string = (unsigned char*)s;
	letro = 0;
	i = 0;
	while (i < n)
	{
		string[i] = letro;
		i++;
	}
}
