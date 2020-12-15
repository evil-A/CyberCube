/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:56:21 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/20 23:27:12 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chain;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	if (!(chain = (char*)malloc(len)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		chain[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		chain[i + j] = s2[j];
		j++;
	}
	chain[i + j] = '\0';
	return (chain);
}
