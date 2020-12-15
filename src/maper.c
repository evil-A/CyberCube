/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:11:11 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 19:12:44 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*line_space(char *line)
{
	while (*line && *line == ' ')
		line++;
	return (line);
}

void	init_map(t_cube *t)
{
	int		x;
	int		y;

	y = 0;
	while (t->maps[y])
	{
		x = 0;
		while (*(t->maps[y] + x))
		{
			if (!(ft_strchr(" 012NSWE", *(t->maps[y] + x))))
				away("wrong character on map");
			if (ft_strchr("2", *(t->maps[y] + x)))
			{
				t->sprite[t->numspri].x = (double)x + 0.5;
				t->sprite[t->numspri].y = (double)y + 0.5;
				t->numspri++;
			}
			if (ft_strchr("NSWE", *(t->maps[y] + x)))
				player_pos(t, x, y);
			x++;
		}
		y++;
	}
}

void	player_pos(t_cube *t, int x, int y)
{
	if (t->pos_x == 0)
	{
		t->pos_x = (int)(x) + 0.5;
		t->pos_y = (int)(y) + 0.5;
		t->dir_x = 0;
		t->dir_y = 0;
		if (*(t->maps[y] + x) == 'N')
			t->dir_y = -1;
		if (*(t->maps[y] + x) == 'S')
			t->dir_y = 1;
		if (*(t->maps[y] + x) == 'E')
			t->dir_x = 1;
		if (*(t->maps[y] + x) == 'W')
			t->dir_x = -1;
		t->plane_x = t->dir_y * -0.66;
		t->plane_y = t->dir_x * 0.66;
	}
	else
		away("posicion repetida");
}

void	flood_fill(t_cube *t, int x, int y)
{
	if (x < 0 || y < 0 || x >= t->x_lim || y >= t->y_lim)
		away("Open map");
	else if (*(t->maps[y] + x) & 128 || *(t->maps[y] + x) == '1')
		return ;
	else if (*(t->maps[y] + x) != ' ')
	{
		*(t->maps[y] + x) |= 128;
		flood_fill(t, x + 1, y);
		flood_fill(t, x, y + 1);
		flood_fill(t, x - 1, y);
		flood_fill(t, x, y - 1);
	}
	else
		away("Open map");
}

void	read_file(t_cube *t)
{
	check_options(t);
	if (param_test(t) != 9)
		away("bad parameters");
	read_map(t, t->line);
}
