/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dist_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:30:56 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/07 09:47:54 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	water_fill(t_cub *cub, int y, int x)
{
	if (cub->map_dist[y][x + 1] != -1
		&& cub->map_dist[y][x + 1] > cub->map_dist[y][x] + 1)
	{
		cub->map_dist[y][x + 1] = cub->map_dist[y][x] + 1;
		water_fill(cub, y, x + 1);
	}
	if (cub->map_dist[y][x - 1] != -1
		&& cub->map_dist[y][x - 1] > cub->map_dist[y][x] + 1)
	{
		cub->map_dist[y][x - 1] = cub->map_dist[y][x] + 1;
		water_fill(cub, y, x - 1);
	}
	if (cub->map_dist[y + 1][x] != -1
		&& cub->map_dist[y + 1][x] > cub->map_dist[y][x] + 1)
	{
		cub->map_dist[y + 1][x] = cub->map_dist[y][x] + 1;
		water_fill(cub, y + 1, x);
	}
	if (cub->map_dist[y - 1][x] != -1
		&& cub->map_dist[y - 1][x] > cub->map_dist[y][x] + 1)
	{
		cub->map_dist[y - 1][x] = cub->map_dist[y][x] + 1;
		water_fill(cub, y - 1, x);
	}
}

void	reinitialize_map_dist(t_cub *cub)
{
	int	i;
	int	j;
	int	door;

	j = -1;
	while (cub->map[++j])
	{
		i = -1;
		while (cub->map[j][++i])
		{
			if (cub->map_dist[j][i] != -1)
				cub->map_dist[j][i] = INT_MAX;
			door = get_door_index(cub->doors, j, i);
			if (door != -1)
			{
				if (cub->doors[door].open == 1)
					cub->map_dist[j][i] = INT_MAX;
				else
					cub->map_dist[j][i] = -1;
			}
		}
	}
}

void	map_dist_manager(t_cub *cub)
{
	reinitialize_map_dist(cub);
	cub->map_dist[(int)cub->player.y][(int)cub->player.x] = 0;
	water_fill(cub, (int)cub->player.y, (int)cub->player.x);
}
