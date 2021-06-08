/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:45:12 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/07 10:45:20 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	log_texture_err(char *err)
{
	ft_error(err);
	exit(0);
}

void	store_no_texture(t_params *p, char *line)
{
	if (p->n_wall_texture.path == NULL)
		p->n_wall_texture.path = line;
	else
		log_texture_err("NO texture assigned more than once.");
}

void	store_ea_texture(t_params *p, char *line)
{
	if (p->e_wall_texture.path == NULL)
		p->e_wall_texture.path = line;
	else
		log_texture_err("EA texture assigned more than once.");
}

void	store_so_texture(t_params *p, char *line)
{
	if (p->s_wall_texture.path == NULL)
		p->s_wall_texture.path = line;
	else
		log_texture_err("SO texture assigned more than once.");
}

void	store_we_texture(t_params *p, char *line)
{
	if (p->w_wall_texture.path == NULL)
		p->w_wall_texture.path = line;
	else
		log_texture_err("WE texture assigned more than once.");
}
