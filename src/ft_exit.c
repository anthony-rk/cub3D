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

int	ft_exit(t_params *params)
{
	mlx_destroy_window(params->mlx, params->win);
	free(params->map);
	deinit_sprites(params);
	printf("Goodbye...\n");
	exit(0);
	return (0);
}
