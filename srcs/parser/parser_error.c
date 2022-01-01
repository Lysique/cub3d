/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:23:09 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 13:48:46 by tamighi          ###   ########.fr       */
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

void	parser_error(t_cub *cub, int error)
{
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	if (error == 1)
		wr_and_ex("Error\nCouldn't open the file.\n", 1);
	else if (error == 2)
	{
		destroy_imgs(cub);
		wr_and_ex("Error\nTexture initialisation didn't work properly.\n", 1);
	}
}
