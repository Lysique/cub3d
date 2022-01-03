/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:46:06 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 13:05:09 by tamighi          ###   ########.fr       */
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

void	keys_init(t_cub *cub, t_key *key)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->s = 0;
	key->right = 0;
	key->left = 0;
	cub->key = *key;
}

void	cub3d(char *argument)
{
	t_cub		cub;
	t_mlx		mlx;
	t_player	player;
	t_key		key;

	mlx_variables_init(&mlx, &cub);
	parser(argument, &cub, &player);
	keys_init(&cub, &key);
	display(&cub);
	mlx_hook(cub.mlx.win, 2, 0, key_press, &cub);
	mlx_hook(cub.mlx.win, 3, 0, key_release, &cub);
	mlx_loop_hook(cub.mlx.mlx, loop_hook, &cub);
	mlx_loop(cub.mlx.mlx);
}
