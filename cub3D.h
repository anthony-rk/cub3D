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

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

#include "libft/libft.h"
#include "../minilibx/mlx.h"

#define WIN_WIDTH 1024
#define WIN_HEIGHT 512

/* The following will need to be extracted from the .cub file */
// #define WIN_WIDTH 1024
// #define WIN_HEIGHT 512
// #define NORTH_TEXTURE_PATH
// #define SOUTH_TEXTURE_PATH
// #define EAST_TEXTURE_PATH
// #define WEST_TEXTURE_PATH
// #define SPRITE_TEXTURE_PATH
// #define FLOOR_COLOR
// #define CEILING_COLOR

// int mapSize_Block = 64;
// int mapX_Blocks = WIN_WIDTH / 64 / 2;
// int mapY_Blocks = WIN_HEIGHT / 64;

#define INT_MAX 2147483647
#define PI 3.1415926535
#define PI2 PI / 2
#define PI3 3 * PI / 2
#define DR 0.0174533
#define PLAYER_SPEED 2;

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT	17

// MAC KEY CODES
#define KEY_ESC		53
#define KEY_Q		12
#define KEY_W		13
#define KEY_E		14
#define KEY_R		15
#define KEY_A		0
#define KEY_S		1
#define KEY_D		2
#define KEY_LARROW	123
#define KEY_RARROW	124

/**************************/
	/* STRUCTS */
/**************************/	

typedef struct		s_params
{
	void    *mlx;
    void    *win;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	// Players variables
	float		x;
	float		y;
	float 		pdx; // the player delta X
	float 		pdy; // the player delta Y
	float 		p_angle; // the player angle

	// Keys that are pressed
	int w;
	int a;
	int s;
	int d;
	int left_arrow;
	int right_arrow; // Button states ON / OFF
	int esc;


	int			max_x;
	int			max_y;
}			t_params;



int		key_press(int keycode, t_params *params);
int		close_window(int keycode, t_params *vars);
void	draw_square(t_params *data, float x, float y, int width, int height, int color);
void	my_mlx_pixel_put(t_params *data, int x, int y, int color);
void	fill_background(t_params *data, int x, int y, int width, int height, int color);
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
void	draw_horiz_line(t_params *data, int x, int y, int len, int color);
void	draw_vert_line(t_params *data, int x, int y, int len, int color);
void	draw_ab_line(t_params *params, float ray_angle, float x, float y, int len, int color);
float	dist(float ax, float ay, float bx, float by);
void	draw_3d_vert_line(t_params *data, int x, int y, int len, int color, int width);

void	draw_player(t_params *params, int color);

void	draw_rays2D(t_params *params);
void	drawMap2D(t_params *data);


void	eval_keys_status(t_params *params);
int		button_up(int keycode, t_params *params);
int		button_down(int keycode, t_params *params);

// Puts the north image for now, can add an arg for different images later
void	my_mlx_img_put(t_params *params, int x, int y);

#endif
