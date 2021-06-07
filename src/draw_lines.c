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

void	draw_horiz_line(t_params *data, int x, int y, int len, int color)
{
	int	i;

	i = -1;
	while (++i < len)
		my_mlx_pixel_put(data, x + i, y, color);
}

void	draw_vert_line(t_params *data, int x, int y, int len, int color)
{
	int	i;

	i = -1;
	while (++i < len)
		my_mlx_pixel_put(data, x, y + i, color);
}

void	draw_3d_vert_line(t_params *data, float x, int y, int len, int color, float width)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < width)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_ab_line(t_params *params, float ray_angle, float x, float y, int len, int color)
{
	float	i;

	i = 0;
	while (i < len)
	{
		my_mlx_pixel_put(params, x + cos(ray_angle) * i, y + sin(ray_angle) * i, color);
		i += 0.1;
	}
}

float	dist(float ax, float ay, float bx, float by)
{
	float	res;

	res = sqrt(((bx - ax)*(bx - ax)) + ((by - ay)*(by - ay)));
	return (res);
}
