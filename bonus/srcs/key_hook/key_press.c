/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:48:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 15:42:28 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

void	key_press_game2(int key, t_cub *cub)
{
	if (key == K_UP && cub->key.shoot_r == 1)
	{
		cub->key.shoot_r = 0;
		cub->key.shoot_p = 1;
	}
	else if (key == K_SHIFT)
		cub->key.swap_gun = 1;
	else if (key == K_DOWN)
		cub->key.reload = 1;
}

void	key_press_game(int key, t_cub *cub)
{
	if (key == K_ESC)
	{
//		error_manager(EXOK);
		mlx_mouse_show();
		cub->game_state = START_MENU;
	}
	else if (key == K_D)
		cub->key.d = 1;
	else if (key == K_A)
		cub->key.a = 1;
	else if (key == K_S)
		cub->key.s = 1;
	else if (key == K_W)
		cub->key.w = 1;
	else if (key == K_LEFT)
		cub->key.left = 1;
	else if (key == K_RIGHT)
		cub->key.right = 1;
	else if (key == K_SPACE && cub->key.door_r == 1)
	{
		cub->key.door_r = 0;
		cub->key.door_p = 1;
	}
	else
		key_press_game2(key, cub);
}

void	key_press_start_menu(int key, t_cub *cub)
{
	if (key == K_ESC)
	{
		mlx_mouse_hide();
		cub->game_state = GAME;
	}
	else if (key == K_SHIFT)
	{
		variables_reset(cub);
		parser("maps/level1.cub", cub);
	}
}	

int	key_press(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (cub->game_state == GAME)
		key_press_game(key, cub);
	else if (cub->game_state == START_MENU)
		key_press_start_menu(key, cub);
	return (0);
}
