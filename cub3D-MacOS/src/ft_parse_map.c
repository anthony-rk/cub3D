/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akowalsk <akowalsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:56:21 by akowalsk          #+#    #+#             */
/*   Updated: 2021/06/06 09:56:30 by akowalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void 	print_map(int **map, int dim_x, int dim_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < dim_y)
	{
		printf("\t");
		j = 0;
		while (j < dim_x)
		{
			printf("%c", (char)map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

static void	check_malloc_y(int **data)
{
	if (!data)
	{
		ft_error("-->Malloc Failed in ft_map_init()");
		free(data);
		exit(0);
	}
}

static void	check_malloc_x(int *data)
{
	if (!data)
	{
		ft_error("-->Malloc Failed in ft_map_init()");
		free(data);
		exit(0);
	}
}

static void	ft_map_init(int ***data_ptr, int dim_x, int dim_y)
{
	int	i;
	int	j;
	int	k;
	int	**data;

	data = (int **) malloc(sizeof(int *) * (dim_y));
	check_malloc_y(data);
	k = -1;
	while (++k < dim_y)
	{
		data[k] = ((int *)malloc(sizeof(int) * (dim_x)));
		check_malloc_x(data[k]);
	}
	i = -1;
	while (++i < dim_y)
	{
		j = -1;
		while (++j < dim_x)
			data[i][j] = '\0';
	}
	*data_ptr = data;
}

void	ft_parse_map(t_params *params, char *av)
{
	ft_map_init(&params->map, params->map_xblocks, params->map_yblocks);
	ft_map_reader(params, av);
	ft_verify_map(params);
}
