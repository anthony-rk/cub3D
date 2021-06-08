/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:41:50 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/03 14:41:51 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_sprite	*new_sprite(t_params *p, int map_x, int map_y)
{
	t_sprite	*s;

	s = (struct s_sprite *)malloc(sizeof(struct s_sprite));
	if (!s)
	{
		ft_error("Sprite memory allocation failed!");
		free(p->map);
		exit(0);
	}
	s->map_x = map_x;
	s->map_y = map_y;
	s->x = 64 * (map_x + 1) - 32;
	s->y = 64 * (map_y + 1) - 32;
	s->dist = dist(p->player.x, p->player.y, s->x, s->y);
	s->ang = get_sprite_angle(p->player.x, p->player.y, s->x, s->y);
	return (s);
}
