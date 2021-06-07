/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:26:33 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/05 15:26:44 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_check_vars_s(t_params *p)
{
	if (p->s_wall_texture.path == NULL)
	{
		ft_error("Missing variable for SO Texture in .cub");
		exit(0);
	}
}

static void	ft_check_vars_e(t_params *p)
{
	if (p->e_wall_texture.path == NULL)
	{
		ft_error("Missing variable for EA Texture in .cub");
		exit(0);
	}
}

static void	ft_check_vars_w(t_params *p)
{
	if (p->w_wall_texture.path == NULL)
	{
		ft_error("Missing variable for WE Texture in .cub");
		exit(0);
	}
}

static void	ft_check_vars_n(t_params *p)
{
	if (p->n_wall_texture.path == NULL)
	{
		ft_error("Missing variable for NO Texture in .cub");
		exit(0);
	}
}

void	ft_check_vars(t_params *p)
{
	ft_check_vars_w(p);
	ft_check_vars_s(p);
	ft_check_vars_e(p);
	ft_check_vars_n(p);
}

/*
// Bonus, check the sprite path
void	ft_check_vars(t_params *p)
{
	ft_check_vars_s(p);
	ft_check_vars_e(p);
	ft_check_vars_n(p);
	ft_check_vars_w(p);
	ft_check_vars_sprite(p);
}
*/