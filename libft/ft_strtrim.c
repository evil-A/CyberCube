/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:29:32 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/25 10:17:33 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_init(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 1;
	while (k == 1)
	{
		k = 0;
		i++;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				k = 1;
			j++;
		}
	}
	return (i);
}

static size_t	ft_end(char const *s1, const char *set, size_t init)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	while (s1[i])
		i++;
	i = i == 0 ? 0 : i - 1;
	k = 1;
	while (init < i && k == 1)
	{
		k = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i--;
				k = 1;
			}
			j++;
		}
	}
	return (i);
}

static char		*ft_trimmer(char const *s1, size_t init, size_t end)
{
	int		i;
	char	*trimmed;

	if (!(trimmed = (char*)malloc(end - init + 2)))
		return (NULL);
	i = 0;
	while (init <= end)
	{
		trimmed[i] = s1[init];
		i++;
		init++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		init;
	int		end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
	{
		if (!(trimmed = (char*)malloc(1)))
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	init = ft_init(s1, set);
	end = ft_end(s1, set, init);
	trimmed = ft_trimmer((char*)s1, init, end);
	return (trimmed);
}
