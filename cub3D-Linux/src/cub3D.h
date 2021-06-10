/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:09:03 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/14 10:13:31 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "../minilibx_linux/mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define INT_MAX 2147483647
# define PI 3.1415926535
# define PI M_PI
# define PI2 M_PI_2
# define DR 0.0174533
# define PLAYER_SPEED 2.5;
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT	17

// LINUX KEY CODES
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_LARROW	65361
# define KEY_RARROW	65363
# define KEY_M		109

/**************************/
	/* STRUCTS */
/**************************/

typedef struct s_point
{
	float	x;
	float	y;
}			t_point;

typedef struct s_square
{
	float	width;
	float	height;
	int		color;
}			t_square;

typedef struct s_raycast
{
	int		r;
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	disT;
	int		has_sprite;
	float	disH;
	float	hx;
	float	hy;
	float	aTan;
	float	disV;
	float	vx;
	float	vy;
	float	nTan;
	float	shade;
	float	ca;
	float	lineH;
	float	lineW;
	float	ty_step;
	float	ty_off;
	float	lineOffset;
	int		color;
	float	ty;
	float	tx;
}			t_raycast;

// Image structure, to hold data from 
// .xpm -> N,E,S,W and Sprite images && main img
typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*path;
}			t_img;

typedef struct s_player
{
	float	x;
	float	y;
	float	pdx;
	float	pdy;
	float	p_angle;
	int		has_player;
}			t_player;

typedef struct s_sprite
{
	float	x;
	float	y;
	float	screenx;
	float	screeny;
	int		map_x;
	int		map_y;
	float	dist;
	float	ang;
}			t_sprite;

// Main struct 
typedef struct s_params
{
	void			*mlx;
	void			*win;
	struct s_img	img;
	struct s_img	n_wall_texture;
	struct s_img	s_wall_texture;
	struct s_img	e_wall_texture;
	struct s_img	w_wall_texture;
	struct s_img	sprite_texture;

	int				floor_color;
	int				ceil_color;

	struct s_player	player;

	int				w;
	int				a;
	int				s;
	int				d;
	int				m;
	int				left_arrow;
	int				right_arrow;
	int				esc;
	int				**map;
	int				max_x;
	int				max_y;
	int				block_size;
	int				map_xblocks;
	int				map_yblocks;
	int				num_sprites;

	int				win_width;
	int				win_height;

	t_sprite		*sprites[100];
}					t_params;

/*******************************/
	/* FUNCTION PROTOTYPES */
/*******************************/

// check_bottons.c
int			button_up(int keycode, t_params *params);
int			button_down(int keycode, t_params *params);

// color_functions.c
int			new_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

// cub_reader.c
void		cub_reader(t_params *params, char *av);
void		ft_reader_error(t_params *params, int fd);

// draw_lines.c
void		draw_horiz_line(t_params *data, t_point pt, int len, int color);
void		draw_wall_line(t_params *p, t_point pt, int y, int color);
void		draw_vert_line(t_params *data, t_point pt, int len, int color);
void		draw_3d_vert_line(t_params *data, t_point pt, int len, int color);
float		dist(float ax, float ay, float bx, float by);

// draw_minimap.c
void		draw_minimap(t_params *params);

// ft_draw_sprite.c
void		draw_sprites(t_params *params, float *wall_dist);

// ft_draw_sprite_utils.c
void		put_sprite(t_params *p, int sprite, float *wall_dist);

// draw_shapes.c
void		fill_background(t_params *params, int x, int y, int color);
void		square(t_params *p, float x, float y, t_square *sq);
void		draw_player(t_params *params, int color);

// get_horiz_line_dist.c
void		get_horiz_line_dist(t_params *p, t_raycast *rc);

// get_vert_line_dist.c
void		get_vert_line_dist(t_params *p, t_raycast *rc);

// fix_angles.c
double		fix_angle(double ang);
double		fix_angle_rad(double ang);

// ft_analyze_map_line.c
void		ft_analyze_map_line(t_params *params, char *line);

// ft_check_filepaths.c
void		ft_check_filepaths(t_params *params);

// ft_check_cub_path.c
void		ft_check_cub_path(char *filename);

// ft_check_cub_vars.c
void		ft_check_cub_vars(t_params *p);

// ft_check_cub_vars_utils.c
void		ft_check_vars_ceil(t_params *p);
void		ft_check_vars_floor(t_params *p);

// ft_draw_walls.c
void		ft_draw_walls(t_params *p, t_raycast *rc);

// ft_error.c
void		ft_error(char *err_message);

// ft_exit.c
int			ft_exit(t_params *params);

// ft_map_reader.c
void		ft_map_reader(t_params *params, char *av);
void		ft_store_map_line(t_params *params, char *line);

// ft_map_reader_utils.c
int			ft_is_direction(char c);
int			ft_is_empty_line(char *str);
void		ft_set_player_pos(t_params *params, int x, int y);
char		ft_set_player_dir(t_params *params, char c);
int			ft_is_valid_map_line(char *str);

// ft_parse_map.c
void		print_map(int **map, int dim_x, int dim_y);
void		ft_parse_map(t_params *params, char *av);

// ft_raycast.c
void		ft_raycast(t_params *params);

// ft_raycast_utils.c
void		init_rc_struct(t_params *p, t_raycast *rc);
void		set_ray_vars_to_shorter(t_params *p, t_raycast *rc);
void		set_line_and_texture_vars(t_params *p, t_raycast *rc);

// ft_verify_map_utils.c
void		ft_check_player(t_params *params);
void		check_top_row(t_params *params);
void		check_bottom_row(t_params *params);
int			check_left_bound(t_params *params, int row);
void		check_right_bound(t_params *params, int row);

// ft_verify_map.c
void		ft_verify_map(t_params *params);

// init_textures_utils.c
void		init_texture_n(t_params *params, char *filepath);
void		init_texture_e(t_params *params, char *filepath);
void		init_texture_s(t_params *params, char *filepath);
void		init_texture_w(t_params *params, char *filepath);
void		init_texture_sprite(t_params *params, char *filepath);

// init_textures.c
void		init_textures(t_params *params);

// handle_resolution.c
void		ft_handle_res(t_params *params, char *line, int skip);

// my_mlx_functions.c
void		my_mlx_pixel_put(t_params *data, int x, int y, int color);

// new_sprite.c
t_sprite	*new_sprite(t_params *params, int map_x, int map_y);

// params_init.c
void		params_init(t_params *params);

// parse_cub.c
void		handle_texture_path(t_params *p, char *line, char dir, int skip);
void		handle_floor_clr(t_params *params, char *line, int skip);
void		handle_ceil_clr(t_params *params, char *line, int skip);

// parse_cub_utils.c
void		log_texture_err(char *err);
void		store_no_texture(t_params *p, char *line);
void		store_ea_texture(t_params *p, char *line);
void		store_so_texture(t_params *p, char *line);
void		store_we_texture(t_params *p, char *line);

// rad_to_degree.c
double		rad_to_degree(double radian);

// sort_sprites.c
void		sort_sprites(t_params *params, int num_sprites);

// sprite_utils.c
double		get_sprite_angle(float ax, float ay, float bx, float by);
void		get_sprite_dist(t_params *params, t_sprite *sprite);
void		init_sprites(t_params *params);
void		deinit_sprites(t_params *params);

// update_player_pos.c
void		update_player_pos(t_params *params);

// update_player_pos_utils.c
void		move_front_or_back(t_params *p, int xo, int yo);
void		handle_rotation(t_params *p);

#endif
