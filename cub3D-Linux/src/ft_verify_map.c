/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:25:10 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/27 11:25:11 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_mid_upwards(t_params *params, int row, int i)
{
	int	j;

	j = 1;
	while (row - j >= 0)
	{
		if (params->map[row - j][i] == ' ')
		{
			ft_error("illegal space in the middle of the map");
			free(params->map);
			printf("Goodbye...\n");
			exit(0);
		}
		else if (params->map[row - j][i] == '1')
			break ;
		j++;
	}
}

static void	check_mid_downwards(t_params *params, int row, int i)
{
	int	j;

	j = 1;
	while (j + row <= params->map_yblocks)
	{
		if (params->map[row + j][i] == ' ')
		{
			ft_error("illegal space in the middle of the map");
			free(params->map);
			printf("Goodbye...\n");
			exit(0);
		}
		else if (params->map[row + j][i] == '1')
			break ;
		j++;
	}
}

static void	check_mid_row(t_params *params, int row)
{
	int	i;

	i = 0;
	i = check_left_bound(params, row);
	check_right_bound(params, row);
	while (i < params->map_xblocks - 1)
	{
		if (params->map[row][i] == '0' || params->map[row][i] == '2')
		{
			check_mid_upwards(params, row, i);
			check_mid_downwards(params, row, i);
		}
		++i;
	}
}

void	ft_verify_map(t_params *params)
{
	int	i;

	i = 0;
	ft_check_player(params);
	check_top_row(params);
	check_bottom_row(params);
	while (++i < params->map_yblocks - 1)
		check_mid_row(params, i);
	ft_check_filepaths(params);
}
