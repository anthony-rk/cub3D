/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:13:02 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/27 14:13:04 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_player(t_params *params)
{
	if (params->player.has_player == 0)
	{
		ft_error("Player does not have a starting location.");
		exit(0);
	}
}

void	check_top_row(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->map_xblocks)
	{
		if (params->map[0][i] != '1' && params->map[0][i] != ' ' )
		{
			ft_error("Top map row is invalid");
			exit(0);
		}
		i++;
	}
}

void	check_bottom_row(t_params *params)
{
	int	i;
	int	y;

	y = params->map_yblocks - 1;
	i = 0;
	while (i < params->map_xblocks)
	{
		if (params->map[y][i] != '1' && params->map[y][i] != ' ' )
		{
			ft_error("Bottom map row is invalid");
			exit(0);
		}
		i++;
	}
}

int	check_left_bound(t_params *params, int row)
{
	int	i;

	i = 0;
	while (params->map[row][i] == ' ')
	{
		printf("%c", params->map[row][i]);
		++i;
	}
	if (params->map[row][i] == '1')
		return (i);
	else
	{
		ft_error("Left Boundary is invalid");
		free(params->map);
		exit(0);
	}
}

void	check_right_bound(t_params *params, int row)
{
	int	i;

	i = params->map_xblocks - 1;
	while (params->map[row][i] == ' ')
		--i;
	if (params->map[row][i] == '1')
		return ;
	else
	{
		ft_error("Right Boundary is invalid");
		free(params->map);
		exit(0);
	}
}
