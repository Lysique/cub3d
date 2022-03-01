/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:26:45 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 14:23:24 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

int	missile_hit_player(t_cub *cub, t_en *en)
{
	if (cub->player.x - 1.5 < en->miss.x && cub->player.x + 1.5 > en->miss.x
		&& cub->player.y - 1.5 < en->miss.y
		&& cub->player.y + 1.5 > en->miss.y)
		return (1);
	return (0);
}

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
		game_state_manager(cub, LOSE);
	}
	cub->shader_index = 20;
}

int	is_en_on_door(t_door door, t_en *en)
{
	int	i;

	i = -1;
	while (en[++i].action != -1)
	{
		if ((int)en[i].x == door.x && (int)en[i].y == door.y
			&& en->life > 0)
			return (1);
	}
	return (0);
}
