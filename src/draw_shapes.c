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

void	fill_background(t_params *params, int x, int y, int color)
{
	square(params, x, y, params->win_width, params->win_height, color);
}

void	square(t_params *p, float x, float y, int width, int height, int c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			my_mlx_pixel_put(p, x + j, y + i, c);
	}
}

void	draw_player(t_params *p, int c)
{
	int		w;
	int		h;
	float	xo;
	float	yo;

	xo = (float)p->block_size * (float)p->map_xblocks / (float)p->win_width * 4.0;
	yo = (float)p->block_size * (float)p->map_yblocks / (float)p->win_height * 4.0;
	w = 10;
	h = 10;
	draw_horiz_line(p, (p->player.x / xo) - w / 2, p->player.y / yo, w, c);
	draw_vert_line(p, p->player.x / xo, (p->player.y / yo) - h / 2, h, c);
}
