/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:26:45 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 13:27:52 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

int	miss_arrived_at_destination(t_miss miss)
{
	float	d_x;
	float	d_y;
	int		x;
	int		y;

	d_x = miss.x - miss.x_dest;
	d_y = miss.y - miss.y_dest;
	y = 0;
	x = 0;
	if (cos(miss.angle) > 0 && d_x >= 0)
		x = 1;
	if (cos(miss.angle) < 0 && d_x <= 0)
		x = 1;
	if (sin(miss.angle) < 0 && d_y >= 0)
		y = 1;
	if (sin(miss.angle) > 0 && d_y <= 0)
		y = 1;
	if (y && x)
		return (1);
	return (0);
}

int	check_p_dir(t_cub *cub, float y, float x)
{
	int	i;

	if (cub->map[(int)y][(int)x] != '1')
		return (1);
	i = get_door_index(cub->doors, (int)y, (int)x);
	if (i != -1 && cub->doors[i].open == 1)
		return (1);
	return (0);
}

void	player_life_manager(t_cub *cub, int life)
{
	cub->player.life -= life;
	if (cub->player.life <= 0)
	{
		cub->player.life = 0;
		cub->game_state = GAME_OVER;
		reinitialize_map_dist(cub);
	}
	cub->shader_index = 10;
}
