/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 13:31:36 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	key_manager(t_cub *cub)
{
	if (cub->map[cub->player.y / UNIT][(cub->player.x + UNIT / 3) / UNIT] != '1')
		cub->player.x += cub->key.d * DISTANCE;
	if (cub->map[cub->player.y / UNIT][(cub->player.x - UNIT / 3) / UNIT] != '1')
		cub->player.x -= cub->key.a * DISTANCE;
	if (cub->map[(cub->player.y + UNIT / 3) / UNIT][cub->player.x / UNIT] != '1')
		cub->player.y += cub->key.s * DISTANCE;
	if (cub->map[(cub->player.y - UNIT / 3)/ UNIT][cub->player.x / UNIT] != '1')
		cub->player.y -= cub->key.w * DISTANCE;
	display_map(cub);
}

int	loop_hook(t_cub *cub)
{
	static int	i = 0;

	if (++i == 100000)
		i = 1;
	if (i % 1000 == 0)
		key_manager(cub);
	return (0);
}
