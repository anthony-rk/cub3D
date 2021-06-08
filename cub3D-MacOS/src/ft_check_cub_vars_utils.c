/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cub_vars_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:43:58 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/07 09:43:59 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_vars_floor(t_params *p)
{
	if (p->floor_color == -1)
	{
		ft_error("Missing variable for F (floor) color in .cub");
		exit(0);
	}
}

void	ft_check_vars_ceil(t_params *p)
{
	if (p->ceil_color == -1)
	{
		ft_error("Missing variable for C (ceiling) color in .cub");
		exit(0);
	}
}
