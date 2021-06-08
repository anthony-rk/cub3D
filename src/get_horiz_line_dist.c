/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_horiz_line_dist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:43:20 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/07 15:43:42 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_horiz_rc_vals(t_params *p, t_raycast *rc)
{
	rc->dof = 0;
	rc->disH = 100000000;
	rc->hx = p->player.x;
	rc->hy = p->player.y;
	rc->aTan = -1 / tan(rc->ra);
	if (rc->ra > PI)
	{
		rc->ry = round((((int)p->player.y >> 6) << 6)) - 0.0001;
		rc->rx = (p->player.y - rc->ry) * rc->aTan + p->player.x;
		rc->yo = -64;
		rc->xo = -(rc->yo) * rc->aTan;
	}
	if (rc->ra < PI)
	{	
		rc->ry = (((int)p->player.y >> 6) << 6) + 64;
		rc->rx = (p->player.y - rc->ry) * rc->aTan + p->player.x;
		rc->yo = 64;
		rc->xo = -(rc->yo) * rc->aTan;
	}
	if (rc->ra == 0 || rc->ra == PI)
	{	
		rc->rx = p->player.x;
		rc->ry = p->player.y;
		rc->dof = 100000000;
	}
}

void	get_horiz_line_dist(t_params *p, t_raycast *rc)
{
	init_horiz_rc_vals(p, rc);
	while (rc->dof < p->map_xblocks || rc->dof < p->map_yblocks)
	{
		rc->mx = (int)(rc->rx) >> 6;
		rc->my = (int)(rc->ry) >> 6;
		if (rc->mx >= 0 && rc->my >= 0 && rc->mx < p->map_xblocks \
				&& rc->my < p->map_yblocks && (p->map[rc->my][rc->mx] == '2'))
			rc->has_sprite = 1;
		if (rc->mx >= 0 && rc->my >= 0 && rc->mx < p->map_xblocks \
				&& rc->my < p->map_yblocks && (p->map[rc->my][rc->mx] == '1'))
		{
			rc->hx = rc->rx;
			rc->hy = rc->ry;
			rc->disH = dist(p->player.x, p->player.y, rc->hx, rc->hy);
			rc->dof = 100000000;
		}
		else
		{
			rc->rx += rc->xo;
			rc->ry += rc->yo;
			rc->dof++;
		}
	}
}
