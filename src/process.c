/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:19:43 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 20:28:28 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map(t_cube *t, char *line)
{
	char	*tp;
	char	*ox1;
	char	*ox2;
	int		bwr;

	t->x_lim = 0;
	t->y_lim = 0;
	ox2 = ft_strjoin(line, "\n");
	while ((bwr = get_next_line(t->fd, &line)) > 0 && *line)
	{
		tp = line;
		ox1 = ft_strjoin(ox2, line);
		free(ox2);
		ox2 = ft_strjoin(ox1, "\n");
		free(ox1);
		t->y_lim++;
		if (t->x_lim < (int)ft_strlen(tp))
			t->x_lim = ft_strlen(tp);
		free(tp);
	}
	map_comp(t, ox2);
	free(line);
	free(ox2);
}

void	check_options(t_cube *t)
{
	while ((t->bwr = get_next_line(t->fd, &t->line)) > 0 && param_test(t) < 9)
	{
		if (empty_line(t))
			continue ;
		else if (!(ft_strncmp(t->line, "R ", 2)))
			t->line = dimension(t, t->line);
		else if (!(ft_strncmp(t->line, "NO ", 3)))
			t->line = wall_read(t, t->line, 0);
		else if (!(ft_strncmp(t->line, "SO ", 3)))
			t->line = wall_read(t, t->line, 1);
		else if (!(ft_strncmp(t->line, "WE ", 3)))
			t->line = wall_read(t, t->line, 2);
		else if (!(ft_strncmp(t->line, "EA ", 3)))
			t->line = wall_read(t, t->line, 3);
		else if (!(ft_strncmp(t->line, "S ", 2)))
			t->line = sprite_read(t, t->line, 4);
		else if (!(ft_strncmp(t->line, "F ", 2)))
			t->line = floor_ceiling(t, t->line, 'F');
		else if (!(ft_strncmp(t->line, "C ", 2)))
			t->line = floor_ceiling(t, t->line, 'C');
		else
			away("Unknown parameter");
		free(t->tp);
	}
}

int		param_test(t_cube *t)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (t->tex[i].file)
			i++;
		else
			break ;
	}
	if (t->width > 0)
		i++;
	if (t->height > 0)
		i++;
	if (t->cel > -1)
		i++;
	if (t->flo > -1)
		i++;
	return (i);
}

int		finish(void)
{
	exit(0);
	return (0);
}

int		empty_line(t_cube *t)
{
	t->tp = t->line;
	t->line = line_space(t->line);
	if (!*t->line)
	{
		free(t->tp);
		return (1);
	}
	return (0);
}
