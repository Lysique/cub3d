/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:59:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/07 09:41:07 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

int	mouse_press(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	error_manager(EXOK);
	return (0);
}

void	mouse_click_game(int key, t_cub *cub)
{
	if (key == 1 && cub->key.shoot_r == 1)
	{
		cub->key.shoot_r = 0;
		cub->key.shoot_p = 1;
	}
	else if (key == 3 || key == 4 || key == 5)
		cub->key.swap_gun = 1;
	else if (key == 2)
		cub->key.reload = 1;
}

int	mouse_click(int key, int x, int y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (cub->game_state == GAME)
		mouse_click_game(key, cub);
	else if (cub->game_state == MAIN_MENU && key == 1)
		mouse_click_main_menu(cub, x, y);
	else if (cub->game_state == LOSE_MENU && key == 1)
		mouse_click_lose_menu(cub, x, y);
	else if (cub->game_state == WIN_MENU && key == 1)
		mouse_click_win_menu(cub, x, y);
	else if (cub->game_state == BREAK_MENU && key == 1)
		mouse_click_break_menu(cub, x, y);
	return (0);
}
