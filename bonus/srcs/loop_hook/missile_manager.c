/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missile_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 07:36:51 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 08:37:37 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	missile_manager(t_en *en, t_cub *cub)
{
	int	i;
	int	j;

	(void)en;
	(void)cub;
	printf("MISSILE THROW\n");
	i = get_door_index(cub->doors, (int)en->miss.y_dest, (int)en->miss.x_dest);
	if (i != -1)
	{
		j = 0;
		cub->map[cub->doors[i].y][cub->doors[i].x] = '0';
		cub->map_dist[cub->doors[i].y][cub->doors[i].x] = INT_MAX;
		while (cub->doors[j].open != -1)
			j++;
		j--;
		cub->doors[i].open = cub->doors[j].open;
		cub->doors[i].is_moving = cub->doors[j].is_moving;
		cub->doors[i].x = cub->doors[j].x;
		cub->doors[i].y = cub->doors[j].y;
		cub->doors[i].sprite = cub->doors[j].sprite;
		cub->doors[j].open = -1;
		j = 0;
		map_dist_manager(cub);
	}
	en->miss.active = 0;
}
