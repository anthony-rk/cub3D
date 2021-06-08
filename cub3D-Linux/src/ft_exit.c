/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@akowalsk.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 09:26:26 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/16 09:26:27 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_textures(t_params *p)
{
	if (p->img.img)
		mlx_destroy_image(p->mlx, p->img.img);
	if (p->n_wall_texture.img)
		mlx_destroy_image(p->mlx, p->n_wall_texture.img);
	if (p->e_wall_texture.img)
		mlx_destroy_image(p->mlx, p->e_wall_texture.img);
	if (p->s_wall_texture.img)
		mlx_destroy_image(p->mlx, p->s_wall_texture.img);
	if (p->w_wall_texture.img)
		mlx_destroy_image(p->mlx, p->w_wall_texture.img);
	if (p->sprite_texture.img)
		mlx_destroy_image(p->mlx, p->sprite_texture.img);
}

int	ft_exit(t_params *params)
{
	mlx_destroy_window(params->mlx, params->win);
	deinit_sprites(params);
	if (params)
		free_textures(params);
	printf("Goodbye...\n");
	exit(0);
	return (0);
}
