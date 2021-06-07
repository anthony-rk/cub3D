/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:36:48 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/27 14:36:50 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_is_direction(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

int	ft_is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || ft_isascii(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_set_player_pos(t_params *params, int x, int y)
{
	params->player.x = (x * 64) + 31;
	params->player.y = (y * 64) + 31;
	params->player.pdx = cos(params->player.p_angle) * PLAYER_SPEED;
	params->player.pdy = sin(params->player.p_angle) * PLAYER_SPEED;
}

char	ft_set_player_dir(t_params *params, char c)
{
	if (c == 'N')
		params->player.p_angle = PI3;
	if (c == 'E')
		params->player.p_angle = 0;
	if (c == 'S')
		params->player.p_angle = PI2;
	if (c == 'W')
		params->player.p_angle = PI;
	return ('0');
}

int	ft_is_valid_map_line(char *str)
{
	int	i;
	int	j;
	int	len;

	len = (int)ft_strlen(str);
	i = 0;
	while (i < len)
	{
		j = -1;
		if (str[i] != '1' && str[i] != '0' && str[i] != '2' && str[i] != ' '
			&& str[i] != '\t' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}
