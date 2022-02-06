/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:21:16 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/06 14:04:03 by tamighi          ###   ########.fr       */
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

void	keys_init(t_cub *cub)
{
	cub->key.w = 0;
	cub->key.s = 0;
	cub->key.a = 0;
	cub->key.d = 0;
	cub->key.right = 0;
	cub->key.left = 0;
	cub->mouse.x = WIN_W / 2;
}

void	imgs_init(t_cub *cub)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	cub->display.img = 0;
	while (i != 0)
		cub->textures[--i].img = 0;
	while (i < NB_SPR)
	{
		while (j < MAX_SPR)
			cub->sprites[i][j++].img = 0;
		j = 0;
		i++;
	}
}

void	structure_init(t_cub *cub)
{
	set_cubptr(cub);
	keys_init(cub);
	cub->map = 0;
	imgs_init(cub);
	cub->mlx.mlx = 0;
	cub->mlx.win = 0;
	mlx_variables_init(cub);
	imgs_creator(cub);
}
