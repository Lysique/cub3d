/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:10:39 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 10:26:19 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	variables_reset(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 6)
		mlx_destroy_image(cub->mlx.mlx, cub->textures[i++].img);
	free(cub->en);
	free(cub->doors);
	free(cub->sprs);
	i = 0;
	while (cub->map[i])
	{
		free(cub->map[i]);
		free(cub->map_dist[i++]);
	}
	free(cub->map);
	free(cub->map_dist);
	variables_init(cub);
}
