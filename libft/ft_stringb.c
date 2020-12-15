/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 23:13:47 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 19:12:40 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putze(t_some *some)
{
	while (some->width > some->len)
	{
		ft_putchar_fd('0', 1);
		some->posline++;
		some->width--;
	}
}

void	stringer(t_some *some)
{
	init_string(some);
	if (some->hyphen == 1)
		strhyp(some);
	else
	{
		some->precision = some->len >= some->precision ?
			some->precision : some->len;
		if (!some->point)
		{
			if (!some->zero)
			{
				while (some->width > some->len)
					putspa(some);
			}
			else if (some->zero)
				putze(some);
		}
		putpo(some);
	}
}
