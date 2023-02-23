/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:52:28 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 14:02:02 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	menu_state_manager(t_cub *cub, int state)
{
	if (cub->game_state == GAME || cub->game_state == LOSE
		|| cub->game_state == WIN)
	{
		mlx_mouse_show(cub->mlx.mlx, cub->mlx.win);
	}
	if (state == WIN_MENU && cub->game_level == 5)
		error_manager(EXOK);
	else
		cub->game_state = state;
}

void	game_state_manager(t_cub *cub, int state)
{
	cub->previous_state = cub->game_state;
	if (state == GAME)
	{
		cub->game_state = state;
		mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, WIN_W / 2, WIN_H / 2);
		key_init(cub);
		mlx_mouse_hide(cub->mlx.mlx, cub->mlx.win);
	}
	else if (state == WIN || state == LOSE)
	{
		if (cub->game_state != GAME)
			mlx_mouse_hide(cub->mlx.mlx, cub->mlx.win);
		cub->game_state = state;
		key_init(cub);
	}
	else
		menu_state_manager(cub, state);
}
