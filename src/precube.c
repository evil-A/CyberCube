/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:16:26 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 20:32:50 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		release(int key, t_cube *t)
{
	if (key == K_W)
		t->walk_dir--;
	if (key == K_S)
		t->walk_dir++;
	if (key == K_A)
		t->walk_side--;
	if (key == K_D)
		t->walk_side++;
	if (key == K_L)
		t->turn_dir++;
	if (key == K_R)
		t->turn_dir--;
	return (0);
}

int		push(int key, t_cube *t)
{
	if (key == K_ESC)
		finish();
	if (key == K_W)
		t->walk_dir++;
	if (key == K_S)
		t->walk_dir--;
	if (key == K_A)
		t->walk_side++;
	if (key == K_D)
		t->walk_side--;
	if (key == K_L)
		t->turn_dir--;
	if (key == K_R)
		t->turn_dir++;
	return (0);
}

void	window_init(t_cube *t)
{
	t->img.img = mlx_new_image(t->ml, t->width, t->height);
	t->img.addr = mlx_get_data_addr(t->img.img, &t->img.bpp,
		&t->img.sizeline, &t->img.endian);
}

void	cube_init(t_cube *t)
{
	int	w;

	t->width = (t->width > MAX_W) ? MAX_W : t->width;
	t->height = (t->height > MAX_H) ? MAX_H : t->height;
	t->mov_speed = 0.12;
	t->rot_speed = 0.03;
	w = 0;
	t->zbuff = malloc(sizeof(double) * t->width);
	if (!(t->ml = mlx_init()) ||
			!(t->wi = mlx_new_window(t->ml, t->width, t->height, "MAPRAYSER")))
		away("mlx went wrong");
	while (w < 5)
	{
		t->tex[w].img = mlx_xpm_file_to_image(t->ml, t->tex[w].file,
				&t->tex[w].width, &t->tex[w].height);
		if (!t->tex[w].img)
			away(".XPM fail");
		if (!(t->tex[w].addr = mlx_get_data_addr(t->tex[w].img, &t->tex[w].bpp,
				&t->tex[w].sizeline, &t->tex[w].endian)))
			away(".XPM fail");
		w++;
	}
}

char	*floor_ceiling(t_cube *t, char *line, char place)
{
	line++;
	line = line_space(line);
	if (place == 'F')
	{
		if (t->flo > -1)
			away("Duplicated parameter");
		flo_color(t, line);
	}
	else if (place == 'C')
	{
		if (t->cel > -1)
			away("Duplicated parameter");
		cel_color(t, line);
	}
	else
		away("Error on floor/ceiling");
	return (line);
}
