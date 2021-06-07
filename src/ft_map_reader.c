/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:04:18 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/17 12:04:20 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void ft_handle_player(t_params *params)
{
	if (params->player.has_player == 1) // it is not carrying over past lines
	{
		ft_error("Player has multiple starting locations.");
		free(params->map);
		exit(0);
	}
}

static void ft_handle_line_contents(t_params *params, char *line, int x, int map_y)
{
	if (ft_is_direction(*line))
	{
		ft_handle_player(params);
		*line = ft_set_player_dir(params, *line);
		ft_set_player_pos(params, x, map_y);
		params->player.has_player = 1;
	}
	params->map[map_y][x] = *line;
	if (params->map[map_y][x] == '2') // there is a sprite
	{
		params->sprites[params->num_sprites] = new_sprite(params, x, map_y);
		params->num_sprites++;
	}
}

static int ft_replace_tabs(t_params *params, int map_y, int x)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		params->map[map_y][x] = ' ';
		x++;
	}
	x--;
	return (x);
}

void	ft_store_map_line(t_params *params, char *line)
{
	int 		x;
	static int	map_y = 0;

	x = -1;
	while (++x < params->map_xblocks && *line)
	{
		if (*line == '\t')
			x = ft_replace_tabs(params, map_y, x);
		else
			ft_handle_line_contents(params, line, x, map_y);
		++line;
	}
	while (x < params->map_xblocks) // fill with spaces
		params->map[map_y][x++] = ' ';
	map_y++;
}

void 	ft_map_reader(t_params *params, char *av)
{
	int 	fd;
	int		ret;
	char	*buff;

	buff = NULL;
	fd = open(av, O_RDONLY);
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		ft_analyze_map_line(params, buff);
		free(buff);
	}
	ft_analyze_map_line(params, buff);
	free(buff);

	if (ret == -1)
	{
		close(fd);
		ft_error("cub_reader returned -1");
		free(params->map);
		exit(0);
	}
	close(fd);
}
