/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:46:06 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 13:24:39 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

void	level_init(char *argument, t_cub *cub)
{
	if (argument)
	{
		cub->game_level = -1;
		parser(argument, cub);
	}
	else
	{
		cub->game_level = 1;
		parser("maps/level1.cub", cub);
	}
	cub->file = argument;
}

void	cub3d(char *argument)
{
	t_cub		cub;

	structure_init(&cub);
	level_init(argument, &cub);
	mlx_hook(cub.mlx.win, 2, 1L<<0, key_press, (void *)&cub);
	mlx_hook(cub.mlx.win, 3, 1L<<1, key_release, (void *)&cub);
	mlx_hook(cub.mlx.win, 4, 1L<<2, mouse_click, (void *)&cub);
	mlx_hook(cub.mlx.win, 5, 1L<<3, mouse_release, (void *)&cub);
	mlx_hook(cub.mlx.win, 6, 1L<<6, mouse_move, (void *)&cub);
	mlx_hook(cub.mlx.win, 17, 0, mouse_press, (void *)&cub);
	mlx_loop_hook(cub.mlx.mlx, loop_hook, &cub);
	mlx_loop(cub.mlx.mlx);
}
