/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/07 09:41:35 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	game_manager(t_cub *cub)
{
	if (cub->shader_index == 20)
		cub->shader_index = -1;
	door_manager(cub);
	player_manager(cub);
	mkits_manager(cub);
	gun_manager(cub);
	emotion_manager(cub);
	enemy_manager(cub);
}

void	fade_out_to_menu(t_cub *cub)
{
	static t_time	time = 0;

	time += cub->time;
	game_manager(cub);
	if (time / 80 > 0)
	{
		cub->shader_index++;
		if (cub->shader_index == 20)
		{
			cub->shader_index = -1;
			mlx_mouse_show();
			if (cub->game_state == WIN)
				game_state_manager(cub, WIN_MENU);
			else
				game_state_manager(cub, LOSE_MENU);
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
	if (cub->game_state == LOSE
		|| cub->game_state == WIN)
		fade_out_to_menu(cub);
	display(cub);
	mlx_do_sync(cub->mlx.mlx);
	return (0);
}
