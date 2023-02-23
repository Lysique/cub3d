/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:59:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 13:45:49 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

int	mouse_press(void *param)
{
    (void)param;
	error_manager(EXOK);
	return (0);
}

int	mouse_click(int key, int x, int y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (cub->game_state == MAIN_MENU && key == 1)
		mouse_click_main_menu(cub, x, y);
	else if (cub->game_state == LOSE_MENU && key == 1)
		mouse_click_lose_menu(cub, x, y);
	else if (cub->game_state == WIN_MENU && key == 1)
		mouse_click_win_menu(cub, x, y);
	else if (cub->game_state == BREAK_MENU && key == 1)
		mouse_click_break_menu(cub, x, y);
	return (0);
}
