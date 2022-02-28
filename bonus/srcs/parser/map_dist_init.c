/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dist_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:37:53 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 13:54:03 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	map_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	fill_map_dist(t_cub *cub, int j)
{
	int	i;

	i = -1;
	while (cub->map[j][++i])
	{
		if (cub->map[j][i] == '1')
			cub->map_dist[j][i] = -1;
		else
			cub->map_dist[j][i] = INT_MAX;
	}
}	

void	map_dist_init(t_cub *cub)
{
	int	i;

	i = -1;
	cub->map_dist = malloc(map_len(cub->map) * (sizeof(int *) + 1));
	if (!cub->map_dist)
		parser_error(MALLOC_ERROR, 0);
	while (cub->map[++i])
	{
		cub->map_dist[i] = malloc(ft_strlen(cub->map[i]) * sizeof(int));
		if (!cub->map_dist[i])
			parser_error(MALLOC_ERROR, 0);
		fill_map_dist(cub, i);
	}
	cub->map_dist[i] = 0;
}
