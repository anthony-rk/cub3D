/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:17:04 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/15 22:17:08 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	texture_paths_init(t_params *p)
{
	p->n_wall_texture.path = NULL;
	p->e_wall_texture.path = NULL;
	p->w_wall_texture.path = NULL;
	p->s_wall_texture.path = NULL;
}

static void	player_init(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->has_player = 0;
	player->p_angle = 1000;
}

void	params_init(t_params *params)
{
	texture_paths_init(params);
	player_init(&params->player);
	params->max_x = 800;
	params->max_y = 600;
	params->win_width = 800;
	params->win_height = 600;
	params->w = 0;
	params->a = 0;
	params->s = 0;
	params->d = 0;
	params->m = -1;
	params->left_arrow = 0;
	params->right_arrow = 0;
	params->esc = 0;
	params->num_sprites = 0;
	params->map_xblocks = 0;
	params->map_yblocks = 0;
	params->block_size = 64;
}
