/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:36:45 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 21:00:58 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		loop_event(t_cube *t)
{
	clock_t	start;
	double	fps;
	char	text[30];

	start = clock();
	if (moneco(t))
	{
		draw(t);
		fps = 1 / ((double)(clock() - start) / CLOCKS_PER_SEC);
		sprintf(text, "FPS %3.0f", fps);
		mlx_string_put(t->ml, t->wi, t->width - 100, 15, 0x000000, text);
	}
	return (1);
}

void	draw(t_cube *t)
{
	int	x;

	x = 0;
	while (x < t->width)
	{
		raycast_column(t, x);
		x++;
	}
	sortsprites(t);
	x = 0;
	while (x < t->numspri)
		tosprites(t, x++);
	mlx_put_image_to_window(t->ml, t->wi, t->img.img, 0, 0);
}

void	tosprites(t_cube *t, int indice)
{
	int	y;

	trasprites(t, indice);
	while (t->stripe < t->sprendx)
	{
		t->texx = (int)(256 * (t->stripe - (-t->sprwidth / 2 + t->sprscreen))
			* t->tex[4].width / t->sprwidth) / 256;
		y = t->sprstarty;
		if (t->trany > 0 && t->stripe > 0 && t->stripe < t->width
				&& t->trany < t->zbuff[t->stripe])
			while (y < t->sprendy)
			{
				t->texy = (int)((((y * 256 - t->height * 128 + t->sprheight
					* 128) * t->tex[4].height) / t->sprheight) / 256);
				t->color = *(int*)(t->tex[4].addr + (t->texy *
					t->tex[4].sizeline + t->texx * t->tex[4].bpp / 8));
				if ((t->color & 0x00ffffff) != 0)
					*(int *)(t->img.addr + (y * t->img.sizeline + t->stripe *
								t->img.bpp / 8)) = t->color;
				y++;
			}
		t->stripe++;
	}
}

void	trasprites(t_cube *t, int indice)
{
	t->sprx = (double)t->sprite[indice].x - t->pos_x;
	t->spry = (double)t->sprite[indice].y - t->pos_y;
	t->inv_det = 1.0 / (t->plane_x * t->dir_y - t->dir_x * t->plane_y);
	t->tranx = t->inv_det * (t->dir_y * t->sprx - t->dir_x * t->spry);
	t->trany = t->inv_det * (-t->plane_y * t->sprx + t->plane_x * t->spry);
	t->sprscreen = (int)((t->width / 2) * (1 + t->tranx / t->trany));
	t->sprheight = ft_fabs((int)t->height / (t->trany));
	t->sprstarty = -t->sprheight / 2 + t->height / 2;
	if (t->sprstarty < 0)
		t->sprstarty = 0;
	t->sprendy = t->sprheight / 2 + t->height / 2;
	if (t->sprendy >= t->height)
		t->sprendy = t->height - 1;
	t->sprwidth = ft_fabs((int)(t->height / (t->trany)));
	t->sprstartx = -t->sprwidth / 2 + t->sprscreen;
	if (t->sprstartx < 0)
		t->sprstartx = 0;
	t->sprendx = t->sprwidth / 2 + t->sprscreen;
	if (t->sprendx >= t->width)
		t->sprendx = t->width - 1;
	t->stripe = t->sprstartx;
}
