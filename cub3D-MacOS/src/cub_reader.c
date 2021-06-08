/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:34:28 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/04 10:34:30 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_map_size(t_params *params, char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	if (params->map_xblocks < len)
		params->map_xblocks = len;
	params->map_yblocks++;
}

static int	is_valid_map_line(char *str)
{
	int	i;
	int	len;

	len = (int)ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != '2' && str[i] != ' '
			&& str[i] != '\t' && str[i] != 'N' && str[i] != 'S' && str[i] != 'E'
			&& str[i] != 'W')
			return (0);
		if (str[i] == ' ')
			str[i] = '1';
		i++;
	}
	return (1);
}

static void	check_texture(t_params *params, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
		handle_texture_path(params, line, 'N', 2 + i);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		handle_texture_path(params, line, 'S', 2 + i);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		handle_texture_path(params, line, 'W', 2 + i);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		handle_texture_path(params, line, 'E', 2 + i);
	else if (line[i] == 'S' && !ft_isalpha(line[i + 1]))
		handle_texture_path(params, line, 'P', 1 + i);
	else if (line[i] == 'F' && !ft_isalpha(line[i + 1]))
		handle_floor_clr(params, line, 1 + i);
	else if (line[i] == 'C' && !ft_isalpha(line[i + 1]))
		handle_ceil_clr(params, line, 1 + i);
}

static void	analyze_line(t_params *params, char *line)
{
	size_t	len;
	int		i;

	len = ft_strlen(line);
	i = -1;
	while (++i < (int)len)
	{
		check_texture(params, line, i);
		if (is_valid_map_line(line) == 1)
		{
			get_map_size(params, line);
			break ;
		}
	}
}

void 	cub_reader(t_params *params, char *av)
{
	int		fd;
	int		ret;
	char	*buff;

	buff = NULL;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
	{
		ft_error("Incorrect filepath regarding .cub argument");
		exit(0);
	}
	ret = get_next_line(fd, &buff);
	while (ret > 0)
	{
		analyze_line(params, buff);
		free(buff);
		ret = get_next_line(fd, &buff);
	}
	analyze_line(params, buff);
	free(buff);
	if (ret == -1)
		ft_reader_error(params, fd);
	close(fd);
	ft_check_cub_vars(params);
	ft_parse_map(params, av);
}
