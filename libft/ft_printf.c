/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 08:02:15 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 19:19:47 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ultrawidth(t_some *some)
{
	if (some->sline[some->pos] == '*')
	{
		some->width = va_arg(some->args, int);
		if (some->width < 0)
		{
			some->hyphen = 1;
			some->width *= -1;
		}
		some->pos++;
	}
	else if (some->sline[some->pos] == '.')
		some->zero = 1;
	else
		while (some->sline[some->pos] >= '0' && some->sline[some->pos] <= '9')
		{
			some->width = (some->width * 10) + some->sline[some->pos] - 48;
			some->pos++;
		}
}

void	ultrapre(t_some *some)
{
	if (some->sline[some->pos] == '*')
	{
		some->precision = va_arg(some->args, int);
		if (some->precision < 0)
		{
			some->precision = 0;
			some->point = 0;
		}
		some->pos++;
	}
	else
		while (some->sline[some->pos] >= '0' && some->sline[some->pos] <= '9')
		{
			some->precision =
				(some->precision * 10) + some->sline[some->pos] - 48;
			some->pos++;
		}
}

void	ultraflags(t_some *some)
{
	while (some->sline[some->pos] == '-' || some->sline[some->pos] == '0')
	{
		if (some->sline[some->pos] == '-')
		{
			some->hyphen = 1;
			some->zero = 0;
		}
		else if (some->sline[some->pos] == '0' && !some->hyphen)
			some->zero = 1;
		some->pos++;
	}
	ultrawidth(some);
	if (some->sline[some->pos] == '.')
	{
		some->point = 1;
		some->pos++;
	}
	ultrapre(some);
}

void	gotoparser(t_some *some)
{
	some->pos++;
	ultraflags(some);
	while (some->sline[some->pos] == ' ')
		some->pos++;
	if (some->sline[some->pos] == '%')
		per(some);
	else if (some->sline[some->pos] == 'c')
		cha(some);
	else if (some->sline[some->pos] == 's')
		stringer(some);
	else if (some->sline[some->pos] == 'd' || some->sline[some->pos] == 'i')
		inter(some);
	else if (some->sline[some->pos] == 'u')
		unsign(some);
	else if (some->sline[some->pos] == 'x')
		hex(some);
	else if (some->sline[some->pos] == 'X')
		hexx(some);
	else if (some->sline[some->pos] == 'p')
		ponter(some);
}

int		ft_printf(const char *line, ...)
{
	t_some	some;

	va_start(some.args, line);
	init_struct(&some);
	some.sline = line;
	while (some.sline[some.pos] != '\0')
	{
		if (some.sline[some.pos] == '%'
			&& ft_strchr("csdiupxX%.-*0123456789 ", some.sline[(some.pos) + 1]))
		{
			gotoparser(&some);
		}
		else
		{
			ft_putchar_fd(some.sline[some.pos], 1);
			some.pos++;
			some.posline++;
			some.val++;
		}
		clean_struct(&some);
	}
	va_end(some.args);
	return (some.posline);
}
