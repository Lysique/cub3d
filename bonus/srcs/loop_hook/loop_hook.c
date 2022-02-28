/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 13:44:01 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	game_over_manager(t_cub *cub)
{
	static t_time	time = 0;
	static int		incr = 1;

	time += cub->time;
	if (time / 300 > 0)
	{
		cub->shader_index += incr;
		if (cub->shader_index == 9)
		{
			variables_reset(cub);
			parser("maps/level1.cub", cub);
			cub->game_state = GAME_OVER;
			cub->shader_index = 9;
			incr = -1;
		}
		if (cub->shader_index == -1)
		{
			incr = 1;
			cub->game_state = GAME;
		}
		time = 0;
	}
}

void	game_manager(t_cub *cub)
{
	if (cub->shader_index == 10)
		cub->shader_index = -1;
	door_manager(cub);
	player_manager(cub);
	gun_manager(cub);
	emotion_manager(cub);
	enemy_manager(cub);
}

int	loop_hook(t_cub *cub)
{
	static t_time	time = 0;

	if (time != 0)
		cub->time = get_time() - time;
	time = get_time();
	if (cub->game_state == GAME || cub->game_state == GAME_OVER)
		game_manager(cub);
	if (cub->game_state == GAME_OVER)
		game_over_manager(cub);
	display(cub);
	mlx_do_sync(cub->mlx.mlx);
	return (0);
}
