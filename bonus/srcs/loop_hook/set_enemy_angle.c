/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemy_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:59:53 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 11:35:43 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	set_north_angle(t_en *en, t_cub *cub, int y, int x)
{
	if (cub->map_dist[y][x + 1] != -1
		&& cub->map_dist[y][x + 1] < cub->map_dist[y][x])
		en->angle = PI / 4;
	else if (cub->map_dist[y][x - 1] != -1
		&& cub->map_dist[y][x - 1] < cub->map_dist[y][x])
		en->angle = 3 * (PI / 4);
	else if (en->x - floor(en->x) < 0.2)
		en->angle = PI / 4;
	else if (en->x - floor(en->x) > 0.8)
		en->angle = 3 * (PI / 4);
	else
		en->angle = PI / 2;
}

void	set_south_angle(t_en *en, t_cub *cub, int y, int x)
{
	if (cub->map_dist[y][x + 1] != -1
		&& cub->map_dist[y][x + 1] < cub->map_dist[y][x])
		en->angle = 7 * (PI / 4);
	else if (cub->map_dist[y][x - 1] != -1
		&& cub->map_dist[y][x - 1] < cub->map_dist[y][x])
		en->angle = 5 * (PI / 4);
	else if (en->x - floor(en->x) < 0.2)
		en->angle = 7 * (PI / 4);
	else if (en->x - floor(en->x) > 0.8)
		en->angle = 5 * (PI / 4);
	else
		en->angle = 3 * (PI / 2);
}

void	set_side_angle(t_en *en, t_cub *cub, int y, int x)
{
	if (cub->map_dist[y][x + 1] != -1
		&& cub->map_dist[y][x + 1] < cub->map_dist[y][x])
		en->angle = 0;
	else if (cub->map_dist[y][x - 1] != -1
		&& cub->map_dist[y][x - 1] < cub->map_dist[y][x])
		en->angle = PI;
	else if (en->x - floor(en->x) < 0.2)
		en->angle = 0;
	else if (en->x - floor(en->x) > 0.8)
		en->angle = PI;
}	

void	set_enemy_angle(t_en *en, t_cub *cub)
{
	int	y;
	int	x;

	y = (int)en->y;
	x = (int)en->x;
	if (cub->map_dist[y + 1][x] != -1
		&& cub->map_dist[y + 1][x] < cub->map_dist[y][x])
		set_south_angle(en, cub, y, x);
	else if (cub->map_dist[y - 1][x] != -1
		&& cub->map_dist[y - 1][x] < cub->map_dist[y][x])
		set_north_angle(en, cub, y, x);
	else if (en->y - floor(en->y) < 0.2)
		set_south_angle(en, cub, y, x);
	else if (en->y - floor(en->y) > 0.8)
		set_north_angle(en, cub, y, x);
	else
		set_side_angle(en, cub, y, x);
}
