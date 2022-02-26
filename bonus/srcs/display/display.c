/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:17:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 15:49:17 by tamighi          ###   ########.fr       */
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
}

void	display_menu(t_cub *cub)
{
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->sprites[I_MENU][0].img, 0, 0);
}

void	display(t_cub *cub)
{
	if (cub->game_state == GAME)
		display_game(cub);
	else if (cub->game_state == MENU)
		display_menu(cub);
}
