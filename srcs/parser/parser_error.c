/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:23:09 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/19 10:23:38 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	destroy_imgs(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (cub->textures[i].img)
			mlx_destroy_image(cub->mlx.mlx, cub->textures[i].img);
		i++;
	}
}

void	free_my_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	parser_error(t_cub *cub, int error)
{
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	while (error >= 2)
	{
		if (error == 2)
		{
			destroy_imgs(cub);
			error--;
		}
		else if (error == 3)
		{
			free_my_arr(cub->map);
			error--;
		}
	}
	exit(1);
}
