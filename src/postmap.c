/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:13:15 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 19:16:01 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*sprite_read(t_cube *t, char *line, int text)
{
	line++;
	line = line_space(line);
	if (t->tex[text].file)
		away("Duplicated parameter");
	t->tex[text].file = ft_strdup(line);
	return (line);
}

char		*wall_read(t_cube *t, char *line, int text)
{
	line += 2;
	line = line_space(line);
	if (t->tex[text].file)
		away("Duplicated parameter");
	t->tex[text].file = ft_strdup(line);
	return (line);
}

char		*dimension(t_cube *t, char *line)
{
	line++;
	line = line_space(line);
	if (t->width > 0 || t->height > 0)
		away("Wrong dimensions parameters");
	if ((t->width = ft_atoi(line)) < 1)
		away("wrong dimensions parameters");
	while ((ft_isdigit(*line) == 1))
		line++;
	line = line_space(line);
	if ((t->height = ft_atoi(line)) < 1)
		away("wrong dimensions parameters");
	while ((ft_isdigit(*line) == 1))
		line++;
	line = line_space(line);
	if (*line && *line != ' ')
		away("Wrong dimensions parameters");
	return (line);
}

void		cel_color(t_cube *t, char *line)
{
	int	rgb;

	rgb = 0;
	t->cel = 0;
	while (*line)
	{
		if ((!ft_isdigit(*line)) && *line && (*line != ' ' || *line != ','))
			away("bad parameter on color");
		while (*line >= '0' && *line <= '9')
		{
			rgb = rgb * 10 + (*line - 48);
			line++;
		}
		if (rgb < 0 || rgb > 255)
			away("Wrong rgb");
		t->cel = (t->cel * 255) + rgb;
		rgb = 0;
		while (*line == ' ' || *line == ',')
			line++;
	}
}

void		flo_color(t_cube *t, char *line)
{
	int	rgb;

	rgb = 0;
	t->flo = 0;
	while (*line)
	{
		if ((!ft_isdigit(*line)) && *line && (*line != ' ' || *line != ','))
			away("bad parameter on color");
		while (*line >= '0' && *line <= '9')
		{
			rgb = rgb * 10 + (*line - 48);
			line++;
		}
		if (rgb < 0 || rgb > 255)
			away("Wrong rgb");
		t->flo = (t->flo * 255) + rgb;
		rgb = 0;
		while (*line == ' ' || *line == ',')
			line++;
	}
}
