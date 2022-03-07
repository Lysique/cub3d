/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:21:16 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/25 15:30:16 by tuytters         ###   ########.fr       */
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

void	imgs_init(t_cub *cub)
{
	int	i;
	int	j;

	i = 7;
	cub->display.img = 0;
	while (i != 0)
		cub->textures[--i].img = 0;
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
	variables_init(cub);
	imgs_init(cub);
	if (access("music/son_ambiance.mp3", F_OK) < 0)
		error_manager(MUSIC_NOT_FOUND);
	system("afplay music/son_ambiance.mp3 &>/dev/null &");
	mlx_variables_init(cub);
	imgs_creator(cub);
}
