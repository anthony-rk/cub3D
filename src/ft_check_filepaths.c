/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_filepaths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:37:00 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/01 13:37:12 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_check_filepath(t_params *params, char *filename)
{
	int		fd;
	char	*out_str;

	out_str = ft_strjoin("Incorrect filepath regarding ", filename);
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
	{
		ft_error(out_str);
		free(params->map);
		free(out_str);
		exit(0);
	}
	free(out_str);
}

void	ft_check_filepaths(t_params *params)
{
	ft_check_filepath(params, params->n_wall_texture.path);
	ft_check_filepath(params, params->e_wall_texture.path);
	ft_check_filepath(params, params->s_wall_texture.path);
	ft_check_filepath(params, params->w_wall_texture.path);
}

/*
// Bonus, check the sprite path
void ft_check_filepaths_bonus(t_params *params)
{
    ft_check_filepath(params, params->n_wall_texture.path);
    ft_check_filepath(params, params->e_wall_texture.path);
    ft_check_filepath(params, params->s_wall_texture.path);
    ft_check_filepath(params, params->w_wall_texture.path);
    ft_check_filepath(params, params->sprite_texture.path);
}
*/