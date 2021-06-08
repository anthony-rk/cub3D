/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:34:42 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/19 14:34:57 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures(t_params *params)
{
	init_texture_n(params, params->n_wall_texture.path);
	init_texture_s(params, params->s_wall_texture.path);
	init_texture_e(params, params->e_wall_texture.path);
	init_texture_w(params, params->w_wall_texture.path);
	init_texture_sprite(params, params->sprite_texture.path);
}
