/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:06:19 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/26 19:06:20 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void 	update_sprite_data(t_params *p, int num_sprites)
{
	int		i;
	double	left_p_angle;
	double	q;

	i = -1;
	while (++i < num_sprites)
	{
		get_sprite_dist(p, p->sprites[i]);
		left_p_angle = 360 - rad_to_degree(p->player.p_angle - (DR * 60 / 2));
		left_p_angle = fix_angle(left_p_angle);
		q = left_p_angle - (p->sprites[i]->ang);
		if ((rad_to_degree(p->player.p_angle)) < 90 && \
				(p->sprites[i]->ang > 270) && q < 0)
			q += 360;
		if ((rad_to_degree(p->player.p_angle)) > 270 && \
				(p->sprites[i]->ang) < 90 && q > 360)
			q -= 360;
		p->sprites[i]->screenx = q * (p->win_width / 60);
		p->sprites[i]->screeny = (p->win_height / 2);
	}
}

void	draw_sprites(t_params *p, float *wall_dist)
{
	int	num_sprites;
	int	i;

	num_sprites = p->num_sprites;
	update_sprite_data(p, num_sprites);
	sort_sprites(p, num_sprites);
	i = -1;
	while (++i < num_sprites)
		put_sprite(p, i, wall_dist);
}
