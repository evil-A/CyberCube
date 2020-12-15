/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:31:48 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 19:32:34 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camdist(t_cube *t)
{
	if (t->drawstart < 0)
		t->drawstart = 0;
	t->drawend = t->line_height / 2 + t->screenheight / 2;
	if (t->drawend >= t->height)
		t->drawend = t->screenheight - 1;
	t->tex_num = *(t->maps[t->map_y] + t->map_x) - 1;
	if (t->side <= 1)
		t->wallx = t->pos_y + t->wall_dist * t->ray_dir_y;
	else
		t->wallx = t->pos_x + t->wall_dist * t->ray_dir_x;
	t->wallx -= floor((t->wallx));
}
