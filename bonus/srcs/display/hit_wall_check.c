/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:12:37 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/19 13:37:56 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	recursive_check(t_ray *r, t_cub *cub)
{
	t_ray		r2;

	if (is_raycast_end(cub, r->map_y, r->map_x))
	{
		draw_line(r, cub);
	}
	else if (get_door_index(cub->doors, r->map_y, r->map_x) != -1)
	{
		r2 = *r;
		hit_wall_check(&r2, cub);
		draw_line(r, cub);
	}
	else
		hit_wall_check(r, cub);
}

void	hit_wall_check(t_ray *r, t_cub *cub)
{
	if (r->side_y < r->side_x)
	{
		r->side_y += r->delta_y;
		r->map_y += r->step_y;
		r->side = SO_NO;
	}
	else
	{
		r->side_x += r->delta_x;
		r->map_x += r->step_x;
		r->side = WE_EA;
	}
	recursive_check(r, cub);
}
