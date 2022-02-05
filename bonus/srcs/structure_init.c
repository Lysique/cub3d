/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:21:16 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/04 11:05:50 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

void	mlx_variables_init(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
		wr_and_ex("Error\nMlx init did not work properly.\n", 1);
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIN_W, WIN_H, "cub3d");
	if (!cub->mlx.win)
		wr_and_ex("Error\nFailed to create window.\n", 1);
}

void	keys_init(t_cub *cub)
{
	cub->key.w = 0;
	cub->key.s = 0;
	cub->key.a = 0;
	cub->key.d = 0;
	cub->key.right = 0;
	cub->key.left = 0;
}

int	textures_img_init(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 6)
		cub->textures[i++].img = 0;
	cub->display.img = mlx_new_image(cub->mlx.mlx, WIN_W, WIN_H);
	if (!cub->display.img)
		return (-1);
	cub->display.addr = mlx_get_data_addr(cub->display.img,
			&cub->display.bpp, &cub->display.sizel, &cub->display.endian);
	return (0);
}

void	structure_init(t_cub *cub)
{
	mlx_variables_init(cub);
	if (textures_img_init(cub) == -1)
	{
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
		wr_and_ex("Error\nImage initialisation failed.\n", 1);
	}
	keys_init(cub);
	cub->map = 0;
}
