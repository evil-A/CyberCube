/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 19:09:38 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 20:58:18 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file(t_cube *t, int argc, char **argv)
{
	int	ch;

	if (argc < 2 || argc > 3)
		away("wrong number of arguments");
	t->fd = open(argv[1], O_RDONLY);
	if (t->fd < 0)
		away("");
	ch = open(argv[1], O_DIRECTORY);
	if (ch > 0)
	{
		close(ch);
		perror("Directory");
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5))
		away("not a .cub");
	t->args = argc;
	t->file = argv;
}

void	init_read(t_cube *t)
{
	ft_bzero(t, sizeof(t_cube));
	t->cel = -1;
	t->flo = -1;
}

double	ft_fabs(double x)
{
	if (x < 0)
		return (x *= -1);
	return (x);
}

void	away(char *msg)
{
	if (!*msg)
		ft_printf("Error\n%s\n", strerror(errno));
	else
		ft_printf("Error\n%s\n", msg);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_cube	t;

	init_read(&t);
	check_file(&t, argc, argv);
	read_file(&t);
	init_map(&t);
	flood_fill(&t, t.pos_x, t.pos_y);
	cube_init(&t);
	window_init(&t);
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", 7))
			screener(&t);
		else
			away("Wrong arguments");
	}
	mlx_hook(t.wi, 17, 0L, finish, &t);
	mlx_hook(t.wi, 2, 1L, push, &t);
	mlx_hook(t.wi, 3, 2L, release, &t);
	mlx_do_key_autorepeatoff(t.ml);
	mlx_loop_hook(t.ml, loop_event, &t);
	draw(&t);
	mlx_loop(t.ml);
	return (0);
}
