/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:55:22 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/15 21:55:40 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_params *params, int x, int y, int color)
{
	char	*dst;

	dst = (char *)params->img.addr + \
		(y * params->img.line_length + x * (params->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
