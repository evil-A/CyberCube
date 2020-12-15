/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:11:23 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/21 23:26:16 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*chain;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen((char*)s))
		return (ft_strdup(""));
	if (!(chain = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && len > 0)
	{
		chain[i] = s[i + start];
		i++;
		len--;
	}
	chain[i] = '\0';
	return (&chain[0]);
}
