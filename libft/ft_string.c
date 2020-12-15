/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 23:13:47 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 19:16:45 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_string(t_some *some)
{
	some->str = va_arg(some->args, char*);
	if (some->str == NULL)
		some->str = "(null)";
	some->len = ft_strlen(some->str);
}

void	point_string(t_some *some)
{
	int	i;

	i = 0;
	while (some->str[i] != '\0' && some->precision > i)
	{
		ft_putchar_fd(some->str[i], 1);
		some->width--;
		i++;
		some->posline++;
	}
}

void	strhyp(t_some *some)
{
	if (some->point)
		point_string(some);
	else if (some->width >= some->len)
	{
		ft_putstr_fd(some->str, 1);
		some->width -= some->len;
		some->posline += some->len;
	}
	else
	{
		ft_putstr_fd(some->str, 1);
		some->posline += some->len;
		some->width = 0;
	}
	while (some->width > 0)
	{
		ft_putchar_fd(' ', 1);
		some->posline++;
		some->width--;
	}
	some->pos++;
}

void	putspa(t_some *some)
{
	ft_putchar_fd(' ', 1);
	some->posline++;
	some->width--;
}

void	putpo(t_some *some)
{
	if (some->point)
	{
		while (some->width > some->precision)
			putspa(some);
		point_string(some);
	}
	else
	{
		ft_putstr_fd(some->str, 1);
		some->posline += some->len;
	}
	some->pos++;
}
