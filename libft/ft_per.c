/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_per.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:47:52 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/14 18:47:09 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	per(t_some *some)
{
	some->str = "%";
	some->len = 1;
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
