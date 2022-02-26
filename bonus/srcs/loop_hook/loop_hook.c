/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 15:11:26 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	game_manager(t_cub *cub)
{
	door_manager(cub);
	player_manager(cub);
	door_manager(cub);
	gun_manager(cub);
	emotion_manager(cub);
	enemy_manager(cub);
	display(cub);
}

int	loop_hook(t_cub *cub)
{
	static t_time	time = 0;

	if (time != 0)
		cub->time = get_time() - time;
	time = get_time();
	if (cub->game_state == GAME)
		game_manager(cub);
	mlx_do_sync(cub->mlx.mlx);
	return (0);
}
