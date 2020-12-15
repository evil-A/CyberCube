/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incube.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:53:36 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 20:31:06 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sortsprites(t_cube *t)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->numspri)
		t->sprite[i].dist = ((t->pos_x - t->sprite[i].x) * (t->pos_x -
			t->sprite[i].x) + (t->pos_y - t->sprite[i].y) *
				(t->pos_y - t->sprite[i].y));
	i = 0;
	while (i < t->numspri)
	{
		j = i + 1;
		while (j <= t->numspri)
		{
			if (t->sprite[j].dist > t->sprite[i].dist)
			{
				t->tmp = t->sprite[i];
				t->sprite[i] = t->sprite[j];
				t->sprite[j] = t->tmp;
			}
			j++;
		}
		i++;
	}
}

void	raycast_column(t_cube *t, int column)
{
	init_cast(t, column);
	stepfind(t);
	hitfind(t);
	distcam(t);
	vert_line(t, column);
	t->zbuff[column] = t->wall_dist;
}

void	distcam(t_cube *t)
{
	if (t->side <= 1)
		t->wall_dist = (t->map_x - t->pos_x +
			(1 - t->stepx) / 2) / t->ray_dir_x;
	else
		t->wall_dist = (t->map_y - t->pos_y +
			(1 - t->stepy) / 2) / t->ray_dir_y;
	t->line_height = (int)(t->screenheight / t->wall_dist);
	t->drawstart = -t->line_height / 2 + t->screenheight / 2;
	camdist(t);
	t->texx = (int)(t->wallx * (double)(t->tex[t->side].width));
	if (t->side <= 1 && t->ray_dir_x > 0)
		t->texx = t->tex[t->side].width - t->texx - 1;
	if (t->side >= 2 && t->ray_dir_y < 0)
		t->texx = t->tex[t->side].width - t->texx - 1;
	t->step = 1.0 * t->tex[t->side].height / t->line_height;
	t->tex_pos = (t->drawstart - t->height / 2 + t->line_height / 2) * t->step;
}

void	hitfind(t_cube *t)
{
	while (t->hit == 0)
	{
		if (t->side_dist_x < t->side_dist_y)
		{
			t->side_dist_x += t->delta_dist_x;
			t->map_x += t->stepx;
			t->side = 0 + (t->stepx < 0);
		}
		else
		{
			t->side_dist_y += t->delta_dist_y;
			t->map_y += t->stepy;
			t->side = 2 + (t->stepy < 0);
		}
		if (*(t->maps[t->map_y] + t->map_x) > 0)
			t->hit = 1;
	}
}

void	stepfind(t_cube *t)
{
	if (t->ray_dir_x < 0)
	{
		t->stepx = -1;
		t->side_dist_x = (t->pos_x - t->map_x) * t->delta_dist_x;
	}
	else
	{
		t->stepx = 1;
		t->side_dist_x = (t->map_x + 1.0 - t->pos_x) * t->delta_dist_x;
	}
	if (t->ray_dir_y < 0)
	{
		t->stepy = -1;
		t->side_dist_y = (t->pos_y - t->map_y) * t->delta_dist_y;
	}
	else
	{
		t->stepy = 1;
		t->side_dist_y = (t->map_y + 1.0 - t->pos_y) * t->delta_dist_y;
	}
}
