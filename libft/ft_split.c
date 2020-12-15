/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 05:53:47 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/25 10:19:59 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_pieces(char const *s, char c)
{
	size_t	pieces;
	int		k;
	int		i;

	pieces = 0;
	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			k = 0;
		else if (k == 0)
		{
			k = 1;
			pieces++;
		}
		i++;
	}
	return (pieces);
}

static size_t	ft_word(char const *s, char c, size_t len)
{
	size_t	word;

	word = 0;
	while (s[len] != '\0' && s[len] != c)
	{
		len++;
		word++;
	}
	return (word);
}

static char		**ft_erase(char **new)
{
	int	p;

	p = 0;
	while (new[p])
	{
		free(new[p]);
		p++;
	}
	free(new);
	return (NULL);
}

static char		**ft_cluster(char const *s, char **new, char c, size_t pieces)
{
	int		i;
	size_t	p;
	int		k;

	i = 0;
	p = 0;
	while (s[i] != '\0' && p < pieces)
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(new[p] = (char*)malloc(sizeof(char) * ft_word(s, c, i) + 1)))
			return (ft_erase(new));
		while (s[i] != '\0' && s[i] != c)
			new[p][k++] = s[i++];
		new[p][k] = '\0';
		p++;
	}
	new[p] = 0;
	return (new);
}

char			**ft_split(char const *s, char c)
{
	char	**new;
	size_t	pieces;

	if (!s)
		return (NULL);
	pieces = ft_pieces(s, c);
	if (!(new = (char**)malloc(sizeof(char*) * (pieces + 1))))
		return (NULL);
	return (ft_cluster(s, new, c, pieces));
}
