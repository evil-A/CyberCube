/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:36:02 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/10 18:23:32 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_struct(t_some *some)
{
	some->sline = 0;
	some->str = NULL;
	some->len = 0;
	some->width = 0;
	some->precision = 0;
	some->zero = 0;
	some->point = 0;
	some->hyphen = 0;
	some->pos = 0;
	some->posline = 0;
	some->val = 0;
}

void	clean_struct(t_some *some)
{
	some->str = NULL;
	some->len = 0;
	some->width = 0;
	some->precision = 0;
	some->zero = 0;
	some->point = 0;
	some->hyphen = 0;
}
