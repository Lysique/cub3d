/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:46:06 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/02 12:31:02 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"
#include "../includes/parser.h"

void	mlx_variables_init(t_mlx *mlx, t_cub *cub)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		wr_and_ex("Error\nMlx init did not work properly.\n", 1);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "cub3d");
	if (!mlx->win)
		wr_and_ex("Error\nFailed to create window.\n", 1);
	cub->mlx = *mlx;
}

void	cub3d(char *argument)
{
	t_cub		cub;
	t_mlx		mlx;
	t_player	player;

	mlx_variables_init(&mlx, &cub);
	parser(argument, &cub, &player);
	display(&cub);
	mlx_key_hook(cub.mlx.win, key_hook, (void *)&cub);
	mlx_loop(cub.mlx.mlx);
}
