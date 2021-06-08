/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:45:37 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/07 11:45:58 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_rc_struct(t_params *p, t_raycast *rc)
{
	rc->r = 0;
	rc->ra = p->player.p_angle - DR * 30;
	rc->ra = fix_angle_rad(rc->ra);
	rc->has_sprite = 0;
}

void	set_ray_vars_to_shorter(t_params *p, t_raycast *rc)
{
	rc->shade = 1.0;
	if (rc->disV < rc->disH)
	{
		rc->rx = rc->vx;
		rc->ry = rc->vy;
		rc->disT = rc->disV;
	}
	else
	{
		rc->shade = 0.5;
		rc->rx = rc->hx;
		rc->ry = rc->hy;
		rc->disT = rc->disH;
	}
	rc->ca = p->player.p_angle - rc->ra;
	rc->ca = fix_angle_rad(rc->ca);
	rc->disT = rc->disT * cos(rc->ca);
	rc->lineH = (p->block_size * p->win_height) / rc->disT;
	rc->ty_step = 63.99 / (float)rc->lineH;
	rc->ty_off = 0;
}

void	set_line_and_texture_vars(t_params *p, t_raycast *rc)
{
	if (rc->lineH > p->win_height)
	{
		rc->ty_off = ((rc->lineH - p->win_height) / 2.0);
		rc->lineH = p->win_height;
	}
	rc->lineOffset = p->win_height / 2 - rc->lineH / 2;
	rc->ty = (rc->ty_off * rc->ty_step);
	if (rc->shade == 0.5)
	{
		rc->tx = (int)(rc->rx) % 64;
		if (rc->ra < PI)
			rc->tx = 63 - rc->tx;
	}
	else
	{
		rc->tx = (int)(rc->ry) % 64;
		if (rc->ra >= PI2 && rc->ra <= PI3)
			rc->tx = 63 - rc->tx;
	}
}
