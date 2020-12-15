/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:43:31 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 19:06:35 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	p_zero(t_some *some)
{
	if (some->str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		some->str++;
		if (some->precision && !some->zero)
			some->precision++;
	}
}

void	p_hyp(t_some *some)
{
	if (some->str[0] == '-' && some->precision)
	{
		ft_putchar_fd('-', 1);
		some->str++;
		some->precision++;
	}
}

void	fix(t_some *some)
{
	if (some->len > some->precision && some->precision)
	{
		some->precision = some->len;
		if (some->str[0] == '-')
			some->precision--;
		if (!some->width)
			some->precision--;
	}
	else if (some->precision > some->width)
	{
		some->width = some->precision;
		if (some->str[0] == '-')
		{
			some->width++;
			if (some->len >= some->precision)
				some->precision++;
		}
	}
}

void	z_val(t_some *some)
{
	some->len = 1;
	if (!some->precision)
	{
		if (!some->width)
		{
			some->str = "";
			some->len = 0;
		}
		else if (!some->precision || some->width)
			some->str = " ";
	}
	else
		some->str = "0";
}

void	p_val(t_some *some)
{
	if (!some->precision)
	{
		if (!some->width && some->point)
			some->str = "";
		else if (!some->point)
		{
			if (!some->precision || some->width)
			{
				some->str = "0";
				some->len = 1;
			}
		}
		else if (some->width && some->point)
			some->str = "";
	}
	else
		some->str = "";
}
