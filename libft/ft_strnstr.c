/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 01:18:04 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/19 01:06:20 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*spoon;
	char	*pin;
	size_t	i;
	size_t	j;

	spoon = (char*)haystack;
	pin = (char*)needle;
	if (pin[0] == '\0')
		return ((char*)spoon);
	i = 0;
	j = 0;
	while (spoon[i] != '\0')
	{
		if (spoon[i] == pin[j] && i < len)
		{
			while (spoon[i + j] == pin[j] && spoon[i + j]
				!= '\0' && pin[j] != '\0' && (i + j) < len)
				j++;
			if (pin[j] == '\0')
				return (&spoon[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
