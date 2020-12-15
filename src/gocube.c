/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gocube.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:51:56 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 20:38:54 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_cast(t_cube *t, int column)
{
	t->screenheight = t->height;
	t->screenwidth = t->width;
	t->camera = 2 * column / (double)t->screenwidth - 1;
	t->ray_dir_x = t->dir_x + t->plane_x * t->camera;
	t->ray_dir_y = t->dir_y + t->plane_y * t->camera;
	t->map_x = (int)t->pos_x;
	t->map_y = (int)t->pos_y;
	t->delta_dist_x = ft_fabs(1 / t->ray_dir_x);
	t->delta_dist_y = ft_fabs(1 / t->ray_dir_y);
	t->hit = 0;
}

void		vert_line(t_cube *t, int x)
{
	int		y;
	int		*dst;

	y = -1;
	while (y++ < t->drawstart)
		*(int *)(t->img.addr + (y * t->img.sizeline + x *
			t->img.bpp / 8)) = t->cel;
	while (y < t->drawend)
	{
		t->texy = (int)t->tex_pos & (t->tex[t->side].height - 1);
		t->tex_pos += t->step;
		t->color = *(int*)(t->tex[t->side].addr + (t->texy *
			t->tex[t->side].sizeline + t->texx * t->tex[t->side].bpp / 8));
		*(int *)(t->img.addr +
			(y * t->img.sizeline + x * t->img.bpp / 8)) = t->color;
		y++;
	}
	while (y < t->height - 1)
	{
		dst = (int *)(t->img.addr + (y * t->img.sizeline + x *
			t->img.bpp / 8));
		*dst = t->flo;
		y++;
	}
}

int			moneco(t_cube *t)
{
	double	speed;

	speed = t->rot_speed * t->turn_dir;
	if (!t->turn_dir && !t->walk_dir && !t->walk_side)
		return (0);
	if (!wall_coll(t, t->pos_x + t->dir_x * t->walk_dir *
			t->mov_speed, t->pos_y))
		t->pos_x = t->pos_x + t->dir_x * t->walk_dir * t->mov_speed;
	if (!wall_coll(t, t->pos_x, t->pos_y + t->dir_y *
			t->walk_dir * t->mov_speed))
		t->pos_y = t->pos_y + t->dir_y * t->walk_dir * t->mov_speed;
	t->odir_x = t->dir_x;
	t->dir_x = t->dir_x * cos(speed) - t->dir_y * sin(speed);
	t->dir_y = t->odir_x * sin(speed) + t->dir_y * cos(speed);
	t->oplane_x = t->plane_x;
	t->plane_x = t->plane_x * cos(speed) - t->plane_y * sin(speed);
	t->plane_y = t->oplane_x * sin(speed) + t->plane_y * cos(speed);
	if (!wall_coll(t, t->pos_x + t->dir_y * t->walk_side *
			t->mov_speed, t->pos_y))
		t->pos_x = t->pos_x + t->dir_y * t->walk_side * t->mov_speed;
	if (!wall_coll(t, t->pos_x, t->pos_y - t->dir_x *
			t->walk_side * t->mov_speed))
		t->pos_y = t->pos_y - t->dir_x * t->walk_side * t->mov_speed;
	return (1);
}

int			wall_coll(t_cube *t, double x, double y)
{
	if (*(t->maps[(int)y] + (int)x) == '1')
		return (1);
	else if ((unsigned char)*(t->maps[(int)y] + (int)x) == ('2' | 128))
		return (1);
	else
		return (0);
}

void		map_comp(t_cube *t, char *strmap)
{
	int x;
	int y;

	if (!(t->maps = malloc(sizeof(char *) * (t->y_lim + 1))))
		away("Map malloc");
	y = 0;
	strmap++;
	while (y < t->y_lim)
	{
		x = 0;
		if (!(t->maps[y] = malloc(sizeof(char) * (t->x_lim + 1))))
			away("Map malloc");
		while (*strmap != '\n' && *strmap)
			*(t->maps[y] + x++) = *(strmap++);
		while (x < t->x_lim)
			*(t->maps[y] + x++) = ' ';
		*(t->maps[y] + x) = '\0';
		strmap++;
		y++;
	}
	t->maps[y] = 0;
}
