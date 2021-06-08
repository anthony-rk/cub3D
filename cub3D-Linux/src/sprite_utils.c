/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:12:06 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/03 11:12:07 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	get_sprite_angle(float ax, float ay, float bx, float by)
{
	double	deltaY;
	double	deltaX;
	double	result;

	deltaY = (ay - by);
	deltaX = (bx - ax);
	result = atan2(deltaY, deltaX) * (180 / M_PI);
	result = fix_angle(result);
	return (result);
}

void	get_sprite_dist(t_params *p, t_sprite *s)
{
	s->dist = dist(p->player.x, p->player.y, s->x, s->y);
	s->ang = get_sprite_angle(p->player.x, p->player.y, s->x, s->y);
}

void	deinit_sprites(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->num_sprites)
	{
		free(params->sprites[i]);
		i++;
	}
}
