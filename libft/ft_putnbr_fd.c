/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 04:15:54 by evila-ro          #+#    #+#             */
/*   Updated: 2019/11/25 10:24:20 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printing(int string_n, int fd)
{
	int	mod;

	if (string_n >= 10)
	{
		ft_putnbr_fd(string_n / 10, fd);
	}
	mod = string_n % 10 + '0';
	write(fd, &mod, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	string_n;
	int	n1;
	int	n2;

	if (n == -2147483648)
	{
		n1 = 21474;
		n2 = 83648;
		write(fd, "-", 1);
		printing(n1, fd);
		printing(n2, fd);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			string_n = n * -1;
		}
		else
		{
			string_n = n;
		}
		printing(string_n, fd);
	}
}
