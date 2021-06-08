/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:09:29 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/07 15:09:46 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_move_left(t_params *p, int xho, int yho)
{
	if (p->a == 1)
	{
		if (p->map[(int)(p->player.y / 64)][(int)((p->player.x + xho) / 64)] \
		== '0' && \
		(p->map[(int)((p->player.y + yho) / 64)][(int)(p->player.x / 64)] \
		== '0'))
		{
			p->player.y += sin(p->player.p_angle - PI2) * 1.3;
			p->player.x += cos(p->player.p_angle - PI2) * 1.3;
		}
		else
		{
			p->player.y -= sin(p->player.p_angle - PI2) * 1.3;
			p->player.x -= cos(p->player.p_angle - PI2) * 1.3;
		}
	}
}

static void	check_move_right(t_params *p, int xho, int yho)
{
	if (p->d == 1)
	{
		if (p->map[(int)(p->player.y / 64)][(int)((p->player.x - xho) / 64)] \
			== '0' && \
			(p->map[(int)((p->player.y - yho) / 64)][(int)(p->player.x / 64)] \
			== '0'))
		{
			p->player.y += sin(p->player.p_angle + PI2) * 1.3;
			p->player.x += cos(p->player.p_angle + PI2) * 1.3;
		}
		else
		{
			p->player.y -= sin(p->player.p_angle + PI2) * 1.3;
			p->player.x -= cos(p->player.p_angle + PI2) * 1.3;
		}
	}
}

static void	move_left_or_right(t_params *p, int xho, int yho)
{
	check_move_left(p, xho, yho);
	check_move_right(p, xho, yho);
}

static void	handle_movement(t_params *p)
{
	int	xo;
	int	yo;
	int	xho;
	int	yho;

	if (p->player.pdx < 0)
		xo = -20;
	else
		xo = 20;
	if (p->player.pdy < 0)
		yo = -20;
	else
		yo = 20;
	if (p->player.pdx < 0)
		xho = -20;
	else
		xho = 20;
	if (p->player.pdy < 0)
		yho = -20;
	else
		yho = 20;
	move_front_or_back(p, xo, yo);
	move_left_or_right(p, xho, yho);
}

void	update_player_pos(t_params *params)
{
	handle_movement(params);
	handle_rotation(params);
	if (params->esc == 1)
		ft_exit(params);
}
