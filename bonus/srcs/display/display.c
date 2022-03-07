/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:17:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 16:51:31 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	display_game(t_cub *cub)
{
	view_casting(cub);
	display_map(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->display.img, 0, 0);
	display_menubar(cub);
	display_char(cub);
	display_gun(cub);
	if (cub->shader_index != -1)
		mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
			cub->sprites[I_SHADERS][cub->shader_index].img, 0, 0);
}

void	display_win_menu(t_cub *cub)
{
	int	x;

	x = 500;
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->sprites[I_MENU][M_WIN].img, 0, 0);
	draw_text(cub, 200, &x, "level ");
	x += 20;
	draw_nb(cub, 170, &x, cub->game_level);
	x += 20;
	draw_text(cub, 200, &x, " completed  ");
	draw_text(cub, 160, &x, "!");
}

void	display_menu(t_cub *cub)
{
	if (cub->game_state == MAIN_MENU)
		mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
			cub->sprites[I_MENU][M_MAIN].img, 0, 0);
	else if (cub->game_state == LOSE_MENU)
		mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
			cub->sprites[I_MENU][M_LOSE].img, 0, 0);
	else if (cub->game_state == WIN_MENU)
		display_win_menu(cub);
	else if (cub->game_state == BREAK_MENU)
		mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
			cub->sprites[I_MENU][M_BREAK].img, 0, 0);
}

void	display(t_cub *cub)
{
	if (cub->game_state == GAME || cub->game_state == LOSE
		|| cub->game_state == WIN)
		display_game(cub);
	else if (cub->game_state == MAIN_MENU
		|| cub->game_state == LOSE_MENU
		|| cub->game_state == WIN_MENU
		|| cub->game_state == BREAK_MENU)
		display_menu(cub);
}
