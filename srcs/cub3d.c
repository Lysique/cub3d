/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:46:06 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 14:46:30 by tamighi          ###   ########.fr       */
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

void	keys_img_init(t_cub *cub, t_key *key, t_img *img)
{
	key->w = 0;
	key->s = 0;
	key->a = 0;
	key->s = 0;
	key->right = 0;
	key->left = 0;
	img->img = mlx_new_image(cub->mlx.mlx, WIN_W, WIN_H);
	if (!img->img)
		free_and_exit(cub, "Error\nImage could not be created.", 1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->sizel, &img->endian);
	cub->display = *img;
	cub->key = *key;
}

void	cub3d(char *argument)
{
	t_cub		cub;
	t_mlx		mlx;
	t_player	player;
	t_key		key;
	t_img		img;

	mlx_variables_init(&mlx, &cub);
	parser(argument, &cub, &player);
	keys_img_init(&cub, &key, &img);
	display(&cub);
	mlx_hook(cub.mlx.win, 2, 0, key_press, &cub);
	mlx_hook(cub.mlx.win, 3, 0, key_release, &cub);
	mlx_loop_hook(cub.mlx.mlx, loop_hook, &cub);
	mlx_loop(cub.mlx.mlx);
}
