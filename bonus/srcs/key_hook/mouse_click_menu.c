/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click_menu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:08:59 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 13:51:36 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

void	level_manager(t_cub *cub, int lvl, int state)
{
	variables_reset(cub);
	if (lvl == -1)
		parser(cub->file, cub);
	else if (lvl == 1)
		parser("maps/level1.cub", cub);
	else if (lvl == 2)
		parser("maps/level2.cub", cub);
	else if (lvl == 3)
		parser("maps/level3.cub", cub);
	else if (lvl == 4)
		parser("maps/level4.cub", cub);
	else if (lvl == 5)
		parser("maps/level5.cub", cub);
	cub->game_level = lvl;
	game_state_manager(cub, state);
}

void	mouse_click_win_menu(t_cub *cub, int x, int y)
{
	if (x > WM_CONTINUE_X && x < WM_CONTINUE_X + BUTTONS_W
		&& y > WM_CONTINUE_Y && y < WM_CONTINUE_Y + BUTTONS_H)
		level_manager(cub, cub->game_level + 1, GAME);
	else if (x > WM_EXIT_X && x < WM_EXIT_X + BUTTONS_W
		&& y > WM_EXIT_Y && y < WM_EXIT_Y + BUTTONS_H)
		error_manager(EXOK);
	else if (x > WM_MMENU_X && x < WM_MMENU_X + BUTTONS_W
		&& y > WM_MMENU_Y && y < WM_MMENU_Y + BUTTONS_H)
	{
		if (cub->game_level == -1)
			level_manager(cub, -1, MAIN_MENU);
		else
			level_manager(cub, 1, MAIN_MENU);
	}
}

void	mouse_click_break_menu(t_cub *cub, int x, int y)
{
	if (x > BM_RETRY_X && x < BM_RETRY_X + BUTTONS_W
		&& y > BM_RETRY_Y && y < BM_RETRY_Y + BUTTONS_H)
		level_manager(cub, cub->game_level, GAME);
	else if (x > BM_EXIT_X && x < BM_EXIT_X + BUTTONS_W
		&& y > BM_EXIT_Y && y < BM_EXIT_Y + BUTTONS_H)
		error_manager(EXOK);
	else if (x > BM_CONTINUE_X && x < BM_CONTINUE_X + BUTTONS_W
		&& y > BM_CONTINUE_Y && y < BM_CONTINUE_Y + BUTTONS_H)
		game_state_manager(cub, cub->previous_state);
	else if (x > BM_MMENU_X && x < BM_MMENU_X + BUTTONS_W
		&& y > BM_MMENU_Y && y < BM_MMENU_Y + BUTTONS_H)
	{
		if (cub->game_level == -1)
			level_manager(cub, -1, MAIN_MENU);
		else
			level_manager(cub, 1, MAIN_MENU);
	}
}

void	mouse_click_lose_menu(t_cub *cub, int x, int y)
{
	if (x > LM_RETRY_X && x < LM_RETRY_X + BUTTONS_W
		&& y > LM_RETRY_Y && y < LM_RETRY_Y + BUTTONS_H)
		level_manager(cub, cub->game_level, GAME);
	else if (x > LM_EXIT_X && x < LM_EXIT_X + BUTTONS_W
		&& y > LM_EXIT_Y && y < LM_EXIT_Y + BUTTONS_H)
		error_manager(EXOK);
	else if (x > LM_MMENU_X && x < LM_MMENU_X + BUTTONS_W
		&& y > LM_MMENU_Y && y < LM_MMENU_Y + BUTTONS_H)
	{
		if (cub->game_level == -1)
			level_manager(cub, -1, MAIN_MENU);
		else
			level_manager(cub, 1, MAIN_MENU);
	}
}

void	mouse_click_main_menu(t_cub *cub, int x, int y)
{
	if (x > MM_PLAY_X && x < MM_PLAY_X + BUTTONS_W
		&& y > MM_PLAY_Y && y < MM_PLAY_Y + BUTTONS_H)
		game_state_manager(cub, GAME);
	else if (x > MM_EXIT_X && x < MM_EXIT_X + BUTTONS_W
		&& y > MM_EXIT_Y && y < MM_EXIT_Y + BUTTONS_H)
		error_manager(EXOK);
}
