/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:12:38 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/22 03:31:58 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int				i;
	unsigned char	*string;

	string = (unsigned char *)s;
	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}
