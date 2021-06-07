/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:01:05 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/06 12:01:06 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_texture_n(t_params *p, char *f)
{
	int	width;
	int	height;

	p->n_wall_texture.img = mlx_xpm_file_to_image(p->mlx, f, &width, &height);
	p->n_wall_texture.addr = (int *)mlx_get_data_addr(p->n_wall_texture.img, \
		&p->n_wall_texture.bits_per_pixel, &p->n_wall_texture.line_length, \
		&p->n_wall_texture.endian);
}

void	init_texture_s(t_params *p, char *f)
{
	int	width;
	int	height;

	p->s_wall_texture.img = mlx_xpm_file_to_image(p->mlx, f, &width, &height);
	p->s_wall_texture.addr = (int *)mlx_get_data_addr(p->s_wall_texture.img, \
		&p->s_wall_texture.bits_per_pixel, &p->s_wall_texture.line_length, \
		&p->s_wall_texture.endian);
}

void	init_texture_e(t_params *p, char *f)
{
	int	width;
	int	height;

	p->e_wall_texture.img = mlx_xpm_file_to_image(p->mlx, f, &width, &height);
	p->e_wall_texture.addr = (int *)mlx_get_data_addr(p->e_wall_texture.img, \
		&p->e_wall_texture.bits_per_pixel, &p->e_wall_texture.line_length, \
		&p->e_wall_texture.endian);
}

void	init_texture_w(t_params *p, char *f)
{
	int	width;
	int	height;

	p->w_wall_texture.img = mlx_xpm_file_to_image(p->mlx, f, &width, &height);
	p->w_wall_texture.addr = (int *)mlx_get_data_addr(p->w_wall_texture.img, \
		&p->w_wall_texture.bits_per_pixel, &p->w_wall_texture.line_length, \
		&p->w_wall_texture.endian);
}

void	init_texture_sprite(t_params *p, char *f)
{
	int	width;
	int	height;

	p->sprite_texture.img = mlx_xpm_file_to_image(p->mlx, f, &width, &height);
	p->sprite_texture.addr = (int *)mlx_get_data_addr(p->sprite_texture.img, \
		&p->sprite_texture.bits_per_pixel, &p->sprite_texture.line_length, \
		&p->sprite_texture.endian);
}
