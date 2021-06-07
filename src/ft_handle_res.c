/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:08:18 by akowalsk          #+#    #+#             */
/*   Updated: 2021/05/04 12:08:26 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_screen_check(t_params *params)
{
	int	max_x;
	int	max_y;

	mlx_get_screen_size(params->mlx, &max_x, &max_y);
	if (max_x < params->win_width)
		params->win_width = max_x;
	if (max_y < params->win_height)
		params->win_height = max_y;
}

static void	ft_check_res(t_params *params, char *width, char *height)
{
	if (ft_atoi(width) <= 0)
	{
		ft_error("Screen Width is not valid");
		ft_exit(params);
	}
	if (ft_atoi(height) <= 0)
	{
		ft_error("Screen Height is not valid");
		ft_exit(params);
	}
}

static char	*ft_get_res_str(char *line)
{
	char	*out;
	int		j;

	j = 0;
	while (ft_isdigit(line[j]))
		j++;
	out = ft_strnew(j);
	return (out);
}

static char	*ft_skip_blanks(char *line, int skip)
{
	while (skip-- > 0)
		++line;
	while (*line && (*line == ' ' || *line == '\t' || *line == '\f'
			|| *line == '\n' || *line == '\v' || *line == '\r'))
		++line;
	return (line);
}

void	ft_handle_res(t_params *params, char *line, int skip)
{
	char	*width;
	char	*height;
	int		i;

	line = ft_skip_blanks(line, skip);
	width = ft_get_res_str(line);
	i = 0;
	while (ft_isdigit((int)*line))
		width[i++] = *line++;
	line = ft_skip_blanks(line, 0);
	height = ft_get_res_str(line);
	i = 0;
	while (ft_isdigit((int)*line))
		height[i++] = *line++;
	ft_check_res(params, width, height);
	params->win_width = ft_atoi(width);
	params->win_height = ft_atoi(height);
	ft_screen_check(params);
	free(width);
	free(height);
	width = NULL;
	height = NULL;
}
