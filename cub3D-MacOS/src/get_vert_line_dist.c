/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vert_line_dist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:50:13 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/07 15:50:33 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_vert_rc_vals(t_params *p, t_raycast *rc)
{
	rc->dof = 0;
	rc->disV = 100000000;
	rc->vx = p->player.x;
	rc->vy = p->player.y;
	rc->nTan = -tan(rc->ra);
	if (rc->ra > PI2 && rc->ra < PI3)
	{
		rc->rx = round((((int)p->player.x >> 6) << 6)) - 0.0001;
		rc->ry = (p->player.x - rc->rx) * rc->nTan + p->player.y;
		rc->xo = -64;
		rc->yo = -(rc->xo) * rc->nTan;
	}
	if (rc->ra < PI2 || rc->ra > PI3)
	{
		rc->rx = (((int)p->player.x >> 6) << 6) + 64;
		rc->ry = (p->player.x - rc->rx) * rc->nTan + p->player.y;
		rc->xo = 64;
		rc->yo = -(rc->xo) * rc->nTan;
	}
	if (rc->ra == PI3 || rc->ra == PI2)
	{
		rc->rx = p->player.x;
		rc->ry = p->player.y;
		rc->dof = 100000000;
	}
}

void	get_vert_line_dist(t_params *p, t_raycast *rc)
{
	init_vert_rc_vals(p, rc);
	while (rc->dof < p->map_xblocks || rc->dof < p->map_yblocks)
	{
		rc->mx = (int)(rc->rx) >> 6;
		rc->my = (int)(rc->ry) >> 6;
		if (rc->mx >= 0 && rc->my >= 0 && rc->mx < p->map_xblocks && \
				rc->my < p->map_yblocks && (p->map[rc->my][rc->mx] == '2'))
			rc->has_sprite = 1;
		if (rc->mx >= 0 && rc->my >= 0 && rc->mx < p->map_xblocks && \
				rc->my < p->map_yblocks && (p->map[rc->my][rc->mx] == '1'))
		{
			rc->vx = rc->rx;
			rc->vy = rc->ry;
			rc->disV = dist(p->player.x, p->player.y, rc->vx, rc->vy);
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
