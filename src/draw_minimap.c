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

void	draw_minimap(t_params *p)
{
	int	x;
	int	y;
	int	xo;
	int	yo;

	xo = p->win_width / p->map_xblocks / 4;
	yo = p->win_height / p->map_yblocks / 4;
	y = -1;
	while (++y < p->map_yblocks)
	{
		x = -1;
		while (++x < p->map_xblocks)
		{
			if (p->map[y][x] == '1')
				square(p, (x * xo), (y * yo), xo, yo, new_trgb(0, 99, 99, 99));
			else
				square(p, (x * xo), (y * yo), xo, yo, new_trgb(0, 0, 0, 0));
			draw_horiz_line(p, x * xo, y * yo, xo, new_trgb(0, 100, 100, 100));
			draw_vert_line(p, x * xo, y * yo, yo, new_trgb(0, 100, 100, 100));
		}
	}
	draw_player(p, new_trgb(50, 255, 255, 255));
}
