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

static void	store_texture(t_params *p, char *line, char dir)
{
	if (dir == 'N')
		store_no_texture(p, line);
	if (dir == 'E')
		store_ea_texture(p, line);
	if (dir == 'S')
		store_so_texture(p, line);
	if (dir == 'W')
		store_we_texture(p, line);
	if (dir == 'P')
	{
		if (p->sprite_texture.path == NULL)
			p->sprite_texture.path = line;
		else
			log_texture_err("SPRITE texture assigned more than once.");
	}
}

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
	store_texture(params, out_str, dir);
}

static void	check_rgb_values(int r, int g, int b, char c)
{
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
	{
		if (c == 'F')
		{
			ft_error("RGB Ceiling / Floor Values are Invalid.");
			exit(0);
		}
		else
		{
			ft_error("RGB Ceiling Values are Invalid.");
			exit(0);
		}
	}
}

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
	check_rgb_values(r, g, b, 'F');
	if (params->floor_color != -1)
	{
		ft_error("F color assigned more than once.");
		exit(0);
	}
	params->floor_color = new_trgb(0, r, g, b);
}

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
	check_rgb_values(r, g, b, 'C');
	if (params->ceil_color != -1)
	{
		ft_error("C color assigned more than once.");
		exit(0);
	}
	params->ceil_color = new_trgb(0, r, g, b);
}
