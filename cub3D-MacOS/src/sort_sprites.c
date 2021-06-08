/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:45:19 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/03 14:45:21 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	swap_sprite_inners(t_sprite *x_ptr, t_sprite *y_ptr)
{
	x_ptr->ang = y_ptr->ang;
	x_ptr->dist = y_ptr->dist;
	x_ptr->map_x = y_ptr->map_x;
	x_ptr->map_y = y_ptr->map_y;
	x_ptr->screenx = y_ptr->screenx;
	x_ptr->screeny = y_ptr->screeny;
	x_ptr->x = y_ptr->x;
	x_ptr->y = y_ptr->y;
}

static void	swap_sprites(t_sprite *x_ptr, t_sprite *y_ptr)
{
	t_sprite	tmp;

	swap_sprite_inners(&tmp, x_ptr);
	swap_sprite_inners(x_ptr, y_ptr);
	swap_sprite_inners(y_ptr, &tmp);
}

void	sort_sprites(t_params *params, int num_sprites)
{
	int	i;
	int	j;

	i = 0;
	while (i < (num_sprites - 1))
	{
		j = 0;
		while (j < (num_sprites - i - 1))
		{
			if (params->sprites[j]->dist < params->sprites[j + 1]->dist)
				swap_sprites(params->sprites[j], params->sprites[j + 1]);
			j++;
		}
		i++;
	}
}
