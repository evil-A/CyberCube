/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:46:16 by evila-ro          #+#    #+#             */
/*   Updated: 2020/12/12 20:39:25 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include <sys/stat.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <time.h>
# include <errno.h>

# define MAX_W		2560
# define MAX_H		1395
# define K_ESC		53
# define K_W		13
# define K_D		2
# define K_S		1
# define K_A		0
# define K_L		123
# define K_R		124
# define PI			3.14159265359
# define WALL_STRIP	1
# define TILE_SIZE	40

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
}				t_sprite;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	char		*file;
	int			bpp;
	int			sizeline;
	int			endian;
	int			height;
	int			width;
}				t_data;

typedef struct	s_ray
{
	int			wall_hitx;
	int			wall_hity;
}				t_ray;

typedef struct	s_cube
{
	int			x;
	int			y;
	double		pos_x;
	double		pos_y;
	int			x_lim;
	int			y_lim;
	int			width;
	int			height;
	int			cel;
	int			flo;
	int			color;
	double		dir_x;
	double		dir_y;
	double		odir_x;
	double		odir_y;
	double		plane_x;
	double		plane_y;
	double		oplane_x;
	double		oplane_y;
	int			turn_dir;
	int			walk_dir;
	int			walk_side;
	double		rot_ang;
	double		mov_speed;
	double		rot_speed;
	double		step;
	double		camera;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		wall_dist;
	double		delta_dist_x;
	double		delta_dist_y;
	double		wallx;
	double		sprx;
	double		spry;
	double		inv_det;
	double		tranx;
	double		trany;
	int			map_x;
	int			map_y;
	int			stepx;
	int			stepy;
	int			drawend;
	int			drawstart;
	int			screenwidth;
	int			screenheight;
	int			side;
	int			hit;
	int			line_height;
	int			sprstartx;
	int			sprstarty;
	int			sprscreen;
	int			sprheight;
	int			sprwidth;
	int			sprendx;
	int			sprendy;
	int			stripe;
	int			tex_num;
	double		tex_pos;
	int			texx;
	int			texy;
	double		*zbuff;
	void		*ml;
	void		*wi;
	int			fd;
	int			args;
	char		**file;
	int			num_rays;
	int			numspri;
	char		*line;
	char		*tp;
	int			bwr;
	char		**maps;
	t_data		img;
	t_data		tex[5];
	t_ray		*rays;
	t_sprite	sprite[4096];
	t_sprite	tmp;
}				t_cube;

int				main(int argc, char **argv);
void			away(char *msg);
double			ft_fabs(double x);
void			init_read(t_cube *t);
void			check_file(t_cube *t, int argc, char **argv);
int				empty_line(t_cube *t);
int				finish(void);
int				param_test(t_cube *t);
void			check_options(t_cube *t);
void			read_map(t_cube *t, char *line);
void			read_file(t_cube *t);
void			flood_fill(t_cube *t, int x, int y);
void			player_pos(t_cube *t, int x, int y);
void			init_map(t_cube *t);
char			*line_space(char *line);
void			flo_color(t_cube *t, char *line);
void			cel_color(t_cube *t, char *line);
char			*dimension(t_cube *t, char *line);
char			*wall_read(t_cube *t, char *line, int text);
char			*sprite_read(t_cube *t, char *line, int text);
char			*floor_ceiling(t_cube *t, char *line, char place);
void			cube_init(t_cube *t);
void			window_init(t_cube *t);
int				push(int key, t_cube *t);
int				release(int key, t_cube *t);
void			map_comp(t_cube *t, char *strmap);
int				wall_coll(t_cube *t, double x, double y);
int				moneco(t_cube *t);
void			vert_line(t_cube *t, int x);
void			init_cast(t_cube *t, int column);
void			stepfind(t_cube *t);
void			hitfind(t_cube *t);
void			camdist(t_cube *t);
void			distcam(t_cube *t);
void			raycast_column(t_cube *t, int column);
void			sortsprites(t_cube *t);
void			trasprites(t_cube *t, int indice);
void			tosprites(t_cube *t, int indice);
void			draw(t_cube *t);
int				loop_event(t_cube *t);
void			intochar(unsigned char *start, int value);
int				writeheader(t_cube *t, int fd, int size);
int				getcolor(t_cube *t, int x, int y);
int				writeimage(t_cube *t, int image, int pad);
void			screener(t_cube *t);

#endif
