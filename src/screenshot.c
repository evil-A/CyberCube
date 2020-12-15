/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:34:42 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 20:50:29 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	intochar(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int		writeheader(t_cube *t, int fd, int size)
{
	int				i;
	unsigned char	header[54];

	i = 0;
	while (i < 54)
		header[i++] = (unsigned char)(0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	intochar(header + 2, size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	intochar(header + 18, t->width);
	intochar(header + 22, t->height);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

int		getcolor(t_cube *t, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(t->img.addr + (y * t->img.sizeline + x * t->img.bpp / 8));
	rgb = (color & 0xff0000) | (color & 0x00ff00) | (color & 0x0000ff);
	return (rgb);
}

int		writeimage(t_cube *t, int image, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					y;
	int					x;
	int					color;

	y = 0;
	while (y < (int)t->height)
	{
		x = 0;
		while (x < (int)t->width)
		{
			color = getcolor(t, x, y);
			if (write(image, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(image, &zero, pad) < 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	screener(t_cube *t)
{
	int	image;
	int	size;
	int	pad;

	draw(t);
	pad = (4 - ((int)t->width * 3) % 4) % 4;
	size = 54 + (3 * ((int)t->width + pad) * (int)t->height);
	if ((image = open("screenshot.bmp", O_CREAT | O_TRUNC | O_RDWR,
			S_IRWXU | S_IRWXG | S_IRWXO)) < 0)
		away(strerror(errno));
	if (!writeheader(t, image, size))
		away("Cabecera no creada");
	if (!writeimage(t, image, pad))
		away("Imagen no escrita");
	close(image);
	exit(0);
}
