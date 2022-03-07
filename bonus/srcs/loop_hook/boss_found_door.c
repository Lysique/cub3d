/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_found_door.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:28:16 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 14:28:06 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

int	is_door_in_the_way(t_ray *r, t_cub *cub, t_en *en)
{
	int	i;

	while (cub->map[r->map_y][r->map_x] != '1')
	{
		if (r->side_y < r->side_x)
		{
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
		}
		else
		{
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
		}
	}
	i = get_door_index(cub->doors, r->map_y, r->map_x);
	if (i != -1)
	{
		en->miss.x_dest = r->map_x + 0.5;
		en->miss.y_dest = r->map_y + 0.5;
		return (1);
	}
	return (0);
}

int	boss_found_door(t_en *en, t_cub *cub)
{
	float	d_x;
	float	d_y;
	t_ray	r;

	d_x = en->x - cub->player.x;
	d_y = en->y - cub->player.y;
	en->angle = get_angle(d_y, d_x);
	r.dir_x = cos(en->angle);
	r.dir_y = sin(en->angle) * -1;
	r.delta_x = sqrtf(1 + (r.dir_y * r.dir_y) / (r.dir_x * r.dir_x));
	r.delta_y = sqrtf(1 + (r.dir_x * r.dir_x) / (r.dir_y * r.dir_y));
	r.map_x = (int)en->x;
	r.map_y = (int)en->y;
	side_init(&r, en->x, en->y);
	return (is_door_in_the_way(&r, cub, en));
}
