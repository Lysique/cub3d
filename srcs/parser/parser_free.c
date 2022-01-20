/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:23:09 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/20 13:49:51 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	destroy_textures(t_cub *cub)
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

void	parser_free(t_cub *cub, char **file)
{
	free_my_arr(file);
	destroy_textures(cub);
	free_my_arr(cub->map);
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
}
