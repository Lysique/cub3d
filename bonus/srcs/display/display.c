/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:17:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 15:37:41 by tamighi          ###   ########.fr       */
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

void	display_start_menu(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->sprites[I_MENU][0].img, 0, 0);
}

void	display(t_cub *cub)
{
	if (cub->game_state == GAME || cub->game_state == GAME_OVER)
		display_game(cub);
	else if (cub->game_state == START_MENU)
		display_start_menu(cub);
}
