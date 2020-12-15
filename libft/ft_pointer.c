/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:47:52 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 19:05:47 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fx(t_some *some)
{
	ft_putstr_fd("0x", 1);
	some->posline += 2;
}

void	pm(t_some *some)
{
	if (some->width)
		some->width -= 2;
	fx(some);
	f_hyp(some);
}

void	pf(t_some *some)
{
	if (some->precision)
		some->precision += 2;
	some->len += 2;
	if (some->precision > some->len + 2)
	{
		fx(some);
		f_left(some);
		some->len -= 2;
	}
	else
	{
		f_left(some);
		some->len -= 2;
		fx(some);
	}
	ft_putstr_fd(some->str, 1);
}

void	pff(t_some *some)
{
	fix(some);
	if (some->hyphen)
		pm(some);
	else if (some->zero)
	{
		fx(some);
		f_z(some);
	}
	else if (!some->hyphen)
		pf(some);
	some->pos++;
	some->posline += some->len;
}

void	ponter(t_some *some)
{
	unsigned long	d;

	d = va_arg(some->args, unsigned long);
	if (!d)
	{
		p_val(some);
	}
	else if (d == 0)
	{
		p_val(some);
	}
	else
	{
		some->str = ft_itox(d);
		some->len = ft_strlen(some->str);
	}
	pff(some);
}
