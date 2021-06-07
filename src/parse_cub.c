/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:41:22 by akowalsk          #+#    #+#             */
/*   Updated: 2021/04/18 18:44:34 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_texture_path(t_params *params, char *line, char dir, int skip)
{
	int		i;
	int		out_len;
	char	*out_str;

	out_str = NULL;
	i = skip;
	out_len = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i + out_len] != ' ' && line[i + out_len] != '\0' \
		&& line[i + out_len] != '\n' && line[i + out_len] != '\t')
		out_len++;
	out_str = ft_strnew(out_len + 2);
	ft_strlcpy(out_str, &line[i], (size_t)out_len + 1);
	if (dir == 'N')
		params->n_wall_texture.path = out_str;
	else if (dir == 'S')
		params->s_wall_texture.path = out_str;
	else if (dir == 'E')
		params->e_wall_texture.path = out_str;
	else if (dir == 'W')
		params->w_wall_texture.path = out_str;
	else if (dir == 'P')
		params->sprite_texture.path = out_str;
}

// if a value is negative, get a seg fault
void	handle_floor_clr(t_params *params, char *line, int skip)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = skip;
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\f' \
			|| line[i] == '\n' || line[i] == '\v' || line[i] == '\r'))
		i++;
	r = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	g = ft_atoi(&line[++i]);
	while (line[i] != ',')
		i++;
	b = ft_atoi(&line[++i]);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
	{
		ft_error("RGB Ceiling Values are Invalid.");
		exit(0);
	}
	params->floor_color = new_trgb(0, r, g, b);
}

// if a value is negative, get a seg fault
void	handle_ceil_clr(t_params *params, char *line, int skip)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = skip;
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == '\f' \
			|| line[i] == '\n' || line[i] == '\v' || line[i] == '\r'))
		i++;
	r = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	g = ft_atoi(&line[++i]);
	while (line[i] != ',')
		i++;
	b = ft_atoi(&line[++i]);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
	{
		ft_error("RGB Ceiling Values are Invalid.");
		exit(0);
	}
	params->ceil_color = new_trgb(0, r, g, b);
}
