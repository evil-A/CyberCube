/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:36:02 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 19:41:04 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoab(int n)
{
	char	*str;
	char	*aux;
	long	nbr;
	int		i;

	nbr = n;
	i = len(nbr);
	if (!(aux = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str = aux;
	free(aux);
	str[i--] = '\0';
	if (nbr == 0)
		return ("0");
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		str[i--] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itu(unsigned n)
{
	char			*str;
	char			*aux;
	unsigned int	nbr;
	int				i;

	nbr = n;
	i = len(nbr);
	if (!(aux = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str = aux;
	free(aux);
	str[i--] = '\0';
	if (nbr == 0)
		return ("0");
	while (nbr > 0)
	{
		str[i--] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itox(unsigned long n)
{
	char				*str;
	char				*aux;
	unsigned long		nbr;
	int					i;

	nbr = n;
	i = lenx(nbr);
	if (!(aux = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str = aux;
	free(aux);
	str[i--] = '\0';
	if (nbr == 0)
		return ("0");
	while (nbr > 0)
	{
		if (nbr % 16 < 10)
			str[i--] = 48 + (nbr % 16);
		else
			str[i--] = 87 + (nbr % 16);
		nbr = nbr / 16;
	}
	return (str);
}

char	*ft_itoxx(unsigned int n)
{
	char				*str;
	char				*aux;
	unsigned int		nbr;
	int					i;

	nbr = n;
	i = lenx(nbr);
	if (!(aux = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str = aux;
	free(aux);
	str[i--] = '\0';
	if (nbr == 0)
		return ("0");
	while (nbr > 0)
	{
		if (nbr % 16 < 10)
			str[i--] = 48 + (nbr % 16);
		else
			str[i--] = 55 + (nbr % 16);
		nbr = nbr / 16;
	}
	return (str);
}
