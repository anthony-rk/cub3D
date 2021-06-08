/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalski@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:16:15 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/07 17:16:42 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_sprite_rc(t_params *p, t_raycast *rc, int sprite)
{
	rc->lineH = (64 * p->win_height) / p->sprites[sprite]->dist;
	rc->lineW = rc->lineH;
	rc->ty_step = 63.9 / (float)rc->lineH;
	rc->ty_off = 0;
	if (rc->lineH > p->win_height)
	{
		rc->ty_off = ((rc->lineH - p->win_height) / 2.0);
		rc->lineH = p->win_height;
	}
	rc->lineOffset = p->win_height / 2 - rc->lineH / 2;
	rc->ty = (rc->ty_off * rc->ty_step);
	rc->tx = 0;
}

static void	draw_right_sprite(t_params *p, t_raycast *rc, int s, float *wd)
{
	t_point	r_pt;
	int		x;
	int		y;

	x = -1;
	while (++x < rc->lineW)
	{
		rc->ty = 0;
		y = -1;
		while (++y < rc->lineH)
		{
			r_pt.x = p->sprites[s]->screenx - rc->lineW / 2 + x;
			r_pt.y = rc->lineOffset + y;
			rc->color = p->sprite_texture.addr[((int)(rc->ty)) *64 \
				+ (int)(rc->tx)];
			if (rc->color != 0 && p->sprites[s]->screenx - rc->lineW / 2 + x < \
					p->win_width && p->sprites[s]->dist < \
					wd[(int)(p->sprites[s]->screenx - rc->lineW / 2 + x)])
				draw_horiz_line(p, r_pt, 1, rc->color);
			rc->ty += rc->ty_step;
		}
		rc->tx += rc->ty_step;
	}
}

static void	draw_left_sprite(t_params *p, t_raycast *rc, int s, float *wd)
{
	t_point	l_pt;
	int		x;
	int		y;

	x = rc->lineW + 1;
	while (--x > 0)
	{
		rc->ty = 0;
		y = -1;
		while (++y < rc->lineH)
		{
			l_pt.x = p->sprites[s]->screenx + rc->lineW / 2 - x;
			l_pt.y = rc->lineOffset + y;
			rc->color = p->sprite_texture.addr[((int)(rc->ty)) *64 \
				+ (int)(rc->tx)];
			if (rc->color != 0 && p->sprites[s]->screenx + rc->lineW / 2 - x > \
			 		0 && p->sprites[s]->dist < \
					wd[(int)(p->sprites[s]->screenx + rc->lineW / 2 - x)])
				draw_horiz_line(p, l_pt, 1, rc->color);
			rc->ty += rc->ty_step;
		}
		rc->tx += rc->ty_step;
	}
}

void	put_sprite(t_params *p, int sprite, float *wall_dist)
{
	t_raycast	r;
	t_raycast	*rc;

	rc = &r;
	init_sprite_rc(p, rc, sprite);
	if (p->sprites[sprite]->screenx > p->win_width / 2)
		draw_right_sprite(p, rc, sprite, wall_dist);
	else
		draw_left_sprite(p, rc, sprite, wall_dist);
}
