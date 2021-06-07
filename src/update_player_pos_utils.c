/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_pos_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:33:09 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/06 12:33:18 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_front_or_back(t_params *p, int xo, int yo)
{
	if (p->w == 1)
	{
		if (p->map[(int)(p->player.y / 64)][(int)((p->player.x + xo) / 64)] == '0')
		{
			p->player.x += p->player.pdx;
		}
		if (p->map[(int)((p->player.y + yo) / 64)][(int)(p->player.x / 64)] == '0')
		{
			p->player.y += p->player.pdy;
		}
	}
	if (p->s == 1)
	{
		if (p->map[(int)(p->player.y / 64)][(int)((p->player.x - xo) / 64)] == '0')
			p->player.x -= p->player.pdx;
		if (p->map[(int)((p->player.y - yo) / 64)][(int)(p->player.x / 64)] == '0')
			p->player.y -= p->player.pdy;
	}
}

void	handle_rotation(t_params *p)
{
	if (p->right_arrow == 1)
	{
		p->player.p_angle += 0.03;
		if (p->player.p_angle > 2 * PI)
			p->player.p_angle -= 2 * PI;
		p->player.pdx = cos(p->player.p_angle) * PLAYER_SPEED;
		p->player.pdy = sin(p->player.p_angle) * PLAYER_SPEED;
	}
	if (p->left_arrow == 1)
	{
		p->player.p_angle -= 0.03;
		if (p->player.p_angle < 0)
			p->player.p_angle += 2 * PI;
		p->player.pdx = cos(p->player.p_angle) * PLAYER_SPEED;
		p->player.pdy = sin(p->player.p_angle) * PLAYER_SPEED;
	}
}