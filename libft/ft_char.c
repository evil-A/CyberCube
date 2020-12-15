/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:30:05 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 15:59:00 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cha(t_some *some)
{
	unsigned int	d;

	d = va_arg(some->args, unsigned int);
	some->len = 1;
	if (!some->point)
		fix(some);
	if (some->hyphen)
		ft_putchar_fd(d, 1);
	while (some->width > some->len)
	{
		ft_putchar_fd(' ', 1);
		some->width--;
		some->posline++;
	}
	if (!some->hyphen)
		ft_putchar_fd(d, 1);
	some->pos++;
	some->posline += some->len;
}
