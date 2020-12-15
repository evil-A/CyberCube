/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 09:01:05 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 19:03:03 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	f_hyp(t_some *some)
{
	p_hyp(some);
	while (some->precision > some->len && some->precision)
	{
		ft_putchar_fd('0', 1);
		some->precision--;
		some->width--;
		some->posline++;
	}
	ft_putstr_fd(some->str, 1);
	while (some->width > some->len)
	{
		ft_putchar_fd(' ', 1);
		some->len++;
	}
}

void	f_z(t_some *some)
{
	if (some->str[0] == '-' && some->precision)
		some->precision++;
	while (some->width > some->precision && some->precision)
	{
		ft_putchar_fd(' ', 1);
		some->width--;
		some->posline++;
	}
	p_zero(some);
	while (some->precision > some->len && some->precision)
	{
		ft_putchar_fd('0', 1);
		some->precision--;
		some->width--;
		some->posline++;
	}
	while (some->width > some->len && !some->precision)
	{
		ft_putchar_fd('0', 1);
		some->width--;
		some->posline++;
	}
	ft_putstr_fd(some->str, 1);
}

void	f_right(t_some *some)
{
	if (some->str[0] == '-')
		some->width--;
	while (some->width > some->precision)
	{
		ft_putchar_fd(' ', 1);
		some->width--;
		some->posline++;
	}
	p_zero(some);
	while (some->precision > some->len)
	{
		ft_putchar_fd('0', 1);
		some->precision--;
		some->posline++;
	}
}

void	f_left(t_some *some)
{
	if (some->precision)
		f_right(some);
	else if (!some->precision)
	{
		while (some->width > some->len)
		{
			ft_putchar_fd(' ', 1);
			some->width--;
			some->posline++;
		}
	}
}

void	inter(t_some *some)
{
	int	d;

	d = va_arg(some->args, int);
	if (d == 0 && !some->val && some->point)
		z_val(some);
	else
	{
		some->str = ft_itoab(d);
		some->len = ft_strlen(some->str);
	}
	fix(some);
	if (some->hyphen)
		f_hyp(some);
	else if (some->zero)
		f_z(some);
	else if (!some->hyphen)
	{
		f_left(some);
		ft_putstr_fd(some->str, 1);
	}
	some->pos++;
	some->posline += some->len;
}
