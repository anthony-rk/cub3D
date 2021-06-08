/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:49:19 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/01 14:49:44 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_background(t_params *p, int x, int y, int c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < p->win_height)
	{
		j = -1;
		while (++j < p->win_width)
			my_mlx_pixel_put(p, x + j, y + i, c);
	}
}

void	square(t_params *p, float x, float y, t_square *sq)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sq->height)
	{
		j = -1;
		while (++j < sq->width)
			my_mlx_pixel_put(p, x + j, y + i, sq->color);
	}
}

void	draw_player(t_params *p, int c)
{
	t_point	horiz_pt;
	t_point	vert_pt;
	float	xo;
	float	yo;

	xo = (float)p->block_size * \
		(float)p->map_xblocks / (float)p->win_width * 4.0;
	yo = (float)p->block_size * \
		(float)p->map_yblocks / (float)p->win_height * 4.0;
	horiz_pt.x = (p->player.x / xo) - 10 / 2;
	horiz_pt.y = p->player.y / yo;
	vert_pt.x = p->player.x / xo;
	vert_pt.y = (p->player.y / yo) - 10 / 2;
	draw_horiz_line(p, horiz_pt, 10, c);
	draw_vert_line(p, vert_pt, 10, c);
}
