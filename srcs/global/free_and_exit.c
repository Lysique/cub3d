/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:11:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 10:22:30 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	free_and_exit(t_cub *cub, char *msg, int error)
{
	int	i;

	i = 0;
	while (cub->map[i])
		free(cub->map[i++]);
	free(cub->map);
	i = 0;
	while (i < 6)
		mlx_destroy_image(cub->mlx.mlx, cub->textures[i++].img);
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	wr_and_ex(msg, error);
}
