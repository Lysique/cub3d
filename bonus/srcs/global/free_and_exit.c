/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:11:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/06 14:13:13 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	free_my_imgs(t_cub *cub, t_img *imgs)
{
	int	i;

	i = 0;
	while (imgs[i].img)
		mlx_destroy_image(cub->mlx.mlx, imgs[i++].img);
}

void	free_my_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_all_imgs(t_cub *cub)
{
	int	j;

	j = 0;
	while (j < NB_SPR)
		free_my_imgs(cub, cub->sprites[j++]);
	free_my_imgs(cub, cub->textures);
	if (cub->display.img)
		mlx_destroy_image(cub->mlx.mlx, cub->display.img);
}

void	free_and_exit(t_cub *cub, int error)
{
	system("killall afplay");
	free_my_arr(cub->map);
	free_all_imgs(cub);
	if (cub->mlx.mlx && cub->mlx.win)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	exit(error);
}
