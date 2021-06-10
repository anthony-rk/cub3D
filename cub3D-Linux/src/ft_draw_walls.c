/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:13:08 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/07 16:13:31 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_vert_wall(t_params *p, t_raycast *rc, t_point wall_point)
{
	int	y;

	y = 0;
	while (y < rc->lineH)
	{
		if (rc->ra >= PI2 && rc->ra <= 3 * PI / 2)
			rc->color = p->e_wall_texture.addr[((int)(rc->ty)) \
				*64 + (int)(rc->tx)];
		else
			rc->color = p->w_wall_texture.addr[((int)(rc->ty)) \
				*64 + (int)(rc->tx)];
		draw_wall_line(p, wall_point, y, rc->color);
		rc->ty += rc->ty_step;
		y++;
	}
}

static void	ft_draw_ceiling(t_params *p, t_raycast *rc, t_point ceil_point)
{
	draw_3d_vert_line(p, ceil_point, rc->lineOffset, p->ceil_color);
}

static void	ft_draw_floor(t_params *p, t_raycast *rc, t_point floor_point)
{
	draw_3d_vert_line(p, floor_point, \
		p->win_height - (rc->lineH + rc->lineOffset), p->floor_color);
}

static void	draw_horiz_wall(t_params *p, t_raycast *rc, t_point wall_point)
{
	int	y;

	y = 0;
	while (y < rc->lineH)
	{
		if (rc->ra < PI)
			rc->color = p->n_wall_texture.addr[((int)(rc->ty)) \
				*64 + (int)(rc->tx)];
		else
			rc->color = p->s_wall_texture.addr[((int)(rc->ty)) \
				*64 + (int)(rc->tx)];
		draw_wall_line(p, wall_point, y, rc->color);
		rc->ty += rc->ty_step;
		y++;
	}
}

void	ft_draw_walls(t_params *p, t_raycast *rc)
{
	t_point	wall_point;
	t_point	ceil_point;
	t_point	floor_point;

	wall_point.x = rc->r;
	wall_point.y = rc->lineOffset;
	ceil_point.x = rc->r;
	ceil_point.y = 0;
	floor_point.x = rc->r;
	floor_point.y = rc->lineOffset + rc->lineH;
	if (rc->disH < rc->disV)
	{
		draw_horiz_wall(p, rc, wall_point);
		ft_draw_ceiling(p, rc, ceil_point);
		ft_draw_floor(p, rc, floor_point);
	}
	else
	{
		draw_vert_wall(p, rc, wall_point);
		ft_draw_ceiling(p, rc, ceil_point);
		ft_draw_floor(p, rc, floor_point);
	}
}
