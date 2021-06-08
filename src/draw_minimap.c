/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:05:55 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/18 10:06:00 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_square	new_square(float width, float height, int color)
{
	t_square	square;

	square.width = width;
	square.height = height;
	square.color = color;
	return (square);
}

void	draw_minimap(t_params *p)
{
	int			x;
	int			y;
	int			xo;
	int			yo;
	t_square	sq;

	xo = p->win_width / p->map_xblocks / 4;
	yo = p->win_height / p->map_yblocks / 4;
	sq = new_square(xo, yo, new_trgb(0, 99, 99, 99));
	y = -1;
	while (++y < p->map_yblocks)
	{
		x = -1;
		while (++x < p->map_xblocks)
		{
			if (p->map[y][x] == '1')
				sq.color = new_trgb(0, 99, 99, 99);
			else if (p->map[y][x] == '2')
				sq.color = new_trgb(0, 255, 50, 50);
			else
				sq.color = new_trgb(0, 0, 0, 0);
			square(p, (x * xo), (y * yo), &sq);
		}
	}
	draw_player(p, new_trgb(50, 0, 255, 255));
}
