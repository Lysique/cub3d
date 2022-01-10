/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 08:46:06 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/10 14:25:52 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"
#include "../includes/parser.h"
#include "../includes/loop_hook.h"

void	mlx_variables_init(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
		wr_and_ex("Error\nMlx init did not work properly.\n", 1);
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIN_W, WIN_H, "cub3d");
	if (!cub->mlx.win)
		wr_and_ex("Error\nFailed to create window.\n", 1);
}

void	keys_img_init(t_cub *cub)
{
	cub->key.w = 0;
	cub->key.s = 0;
	cub->key.a = 0;
	cub->key.s = 0;
	cub->key.right = 0;
	cub->key.left = 0;
	cub->display.img = mlx_new_image(cub->mlx.mlx, WIN_W, WIN_H);
	if (!cub->display.img)
		free_and_exit(cub, "Error\nImage could not be created.", 1);
	cub->display.addr = mlx_get_data_addr(cub->display.img,
		&cub->display.bpp, &cub->display.sizel, &cub->display.endian);
}

void	cub3d(char *argument)
{
	t_cub		cub;

	key_init(&cub);
	mlx_variables_init(&cub);
	parser(argument, &cub);
	keys_img_init(&cub);
	display(&cub);
	mlx_hook(cub.mlx.win, 2, 0, key_press, &cub);
	mlx_hook(cub.mlx.win, 3, 0, key_release, &cub);
	mlx_hook(cub.mlx.win, 17, 0, mouse_press, &cub);
	mlx_loop_hook(cub.mlx.mlx, loop_hook, &cub);
	mlx_loop(cub.mlx.mlx);
}
