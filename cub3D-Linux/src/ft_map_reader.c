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

static void	ft_handle_player(t_params *params)
{
	if (params->player.has_player == 1)
	{
		ft_error("Player has multiple starting locations.");
		exit(0);
	}
}

static void	ft_handle_line_contents(t_params *p, char *l, int x, int map_y)
{
	if (ft_is_direction(*l))
	{
		ft_handle_player(p);
		*l = ft_set_player_dir(p, *l);
		ft_set_player_pos(p, x, map_y);
		p->player.has_player = 1;
	}
	p->map[map_y][x] = *l;
	if (p->map[map_y][x] == '2')
	{
		p->sprites[p->num_sprites] = new_sprite(p, x, map_y);
		p->num_sprites++;
	}
}

static int	ft_replace_tabs(t_params *params, int map_y, int x)
{
	int	i;

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
	int			x;
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
	while (x < params->map_xblocks)
		params->map[map_y][x++] = ' ';
	map_y++;
}

void 	ft_map_reader(t_params *params, char *av)
{
	int		fd;
	int		ret;
	char	*buff;

	buff = NULL;
	fd = open(av, O_RDONLY);
	ret = get_next_line(fd, &buff);
	while (ret > 0)
	{
		ft_analyze_map_line(params, buff);
		free(buff);
		ret = get_next_line(fd, &buff);
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
