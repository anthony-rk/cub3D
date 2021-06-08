/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:07:48 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/15 22:07:52 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_horiz_line(t_params *data, t_point pt, int len, int color)
{
	int	i;

	i = -1;
	while (++i < len)
		my_mlx_pixel_put(data, pt.x + i, pt.y, color);
}

void	draw_wall_line(t_params *p, t_point pt, int y, int color)
{
	my_mlx_pixel_put(p, pt.x, pt.y + y, color);
}

void	draw_vert_line(t_params *data, t_point pt, int len, int color)
{
	int	i;

	i = -1;
	while (++i < len)
		my_mlx_pixel_put(data, pt.x, pt.y + i, color);
}

void	draw_3d_vert_line(t_params *data, t_point pt, int len, int color)
{
	int	i;

	i = 0;
	while (i < len)
	{
		my_mlx_pixel_put(data, pt.x, pt.y + i, color);
		i++;
	}
}

float	dist(float ax, float ay, float bx, float by)
{
	float	res;

	res = sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay)));
	return (res);
}
