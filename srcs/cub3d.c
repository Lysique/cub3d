/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:46:06 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 16:47:25 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"
#include "../includes/parser.h"

void	mlx_variables_init(t_mlx *mlx, t_cub *cub)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		my_write("Error\nMlx init did not work properly.\n");
	mlx->win = mlx_new_window(mlx->mlx, 1920, 1080, "cub3d");
	if (!mlx->win)
		my_write("Error\nFailed to create window.\n");
	cub->mlx = *mlx;
}

void	cub3d(char *argument)
{
	t_cub	cub;
	t_mlx	mlx;

	mlx_variables_init(&mlx, &cub);
	parser(argument, &cub);
	mlx_key_hook(cub.mlx.win, key_hook, (void *)&cub);
	mlx_loop(cub.mlx.mlx);
}
