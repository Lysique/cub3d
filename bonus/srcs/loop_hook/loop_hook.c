/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 15:57:34 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

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

void	game_over_manager(t_cub *cub)
{
	static t_time	time = 0;

	time += cub->time;
	game_manager(cub);
	if (time / 300 > 0)
	{
		cub->shader_index++;
		if (cub->shader_index == 9)
		{
			variables_reset(cub);
			parser("maps/level1.cub", cub);
			mlx_mouse_show();
			cub->game_state = START_MENU;
		}
		time = 0;
	}
}

int	loop_hook(t_cub *cub)
{
	static t_time	time = 0;

	if (time != 0)
		cub->time = get_time() - time;
	time = get_time();
	if (cub->game_state == GAME)
		game_manager(cub);
	else if (cub->game_state == GAME_OVER)
		game_over_manager(cub);
	display(cub);
	mlx_do_sync(cub->mlx.mlx);
	return (0);
}
