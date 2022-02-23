/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:46:21 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/23 10:18:55 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	ennemy_move(t_en *en, t_cub *cub)
{
	(void)cub;
	en->x += cos(en->angle) * 0.05;
	en->y += sin(en->angle) * -0.05;
}
void	set_en_angle(t_en *en, t_cub *cub)
{
	int		x;
	int		y;

	x = (int)en->x;
	y = (int)en->y;
	if (cub->map_dist[y + 1][x] != -1 && cub->map_dist[y + 1][x] < cub->map_dist[y][x])
		en->angle = 3 * PI / 2;
	else if (cub->map_dist[y - 1][x] != -1 && cub->map_dist[y - 1][x] < cub->map_dist[y][x])
		en->angle = PI / 2;
	else
	{
		if (en->y - floor(en->y) > 0.8)
			en->angle = PI / 2;
		else if (en->y - floor(en->y) < 0.2)
			en->angle = 3 * PI / 2;
		else
			en->angle = PI;
	}
	en->angle -= PI;
	if (cub->map_dist[y][x + 1] != -1 && cub->map_dist[y][x + 1] < cub->map_dist[y][x])
		en->angle = 2 * PI - en->angle / 2;
	else if (cub->map_dist[y][x - 1] != -1 && cub->map_dist[y][x - 1] < cub->map_dist[y][x])
		en->angle = PI + en->angle / 2;
	else
	{
		if (en->x - floor(en->x) > 0.8)
			en->angle = PI + en->angle / 2;
		else if (en->x - floor(en->x) < 0.2)
			en->angle = 2 * PI - en->angle / 2;
		else
			en->angle -= PI;
	}
}

void	manage_ennemy(t_en *en, t_cub *cub)
{
	if (en->life > 0 && cub->map_dist[(int)en->y][(int)en->x] != 0)
	{
		set_en_angle(en, cub);
		ennemy_move(en, cub);
	}
}

void	ennemy_manager(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->en[++i].action != -1)
		manage_ennemy(&cub->en[i], cub);
}
