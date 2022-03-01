/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:21:16 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 13:22:58 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

void	mlx_variables_init(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
		error_manager(MLX_ERROR);
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIN_W, WIN_H, "cub3d");
	if (!cub->mlx.win)
		error_manager(MLX_ERROR);
}

void	pre_variables_init(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	cub->mlx.mlx = 0;
	cub->mlx.win = 0;
	cub->display.img = 0;
	cub->game_state = MAIN_MENU;
	while (i < NB_SPR)
	{
		j = 0;
		while (j < MAX_SPR)
			cub->sprites[i][j++].img = 0;
		i++;
	}
}

void	structure_init(t_cub *cub)
{
	set_cubptr(cub);
	pre_variables_init(cub);
	variables_init(cub);
	if (access("music/son_ambiance.mp3", F_OK) < 0)
		error_manager(MUSIC_NOT_FOUND);
	mlx_variables_init(cub);
	imgs_creator(cub);
}
