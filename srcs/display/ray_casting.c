/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:14:29 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/29 15:42:43 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	hit_wall_check(t_ray *r, t_cub *cub)
{
	while (r->hit == 0)
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
		if (cub->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
	if (r->side == WE_EA)
		r->wall_dist = r->side_x - r->delta_x;
	else
		r->wall_dist = r->side_y - r->delta_y;
}

void	side_init(t_ray *r, t_player p)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_x = (float)(p.x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (float)(p.x - 1 - r->map_x) * (r->delta_x * -1);
	}
	if (r->dir_y > 0)
	{
		r->step_y = -1;
		r->side_y = (float)(p.y - r->map_y) * r->delta_y ;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (float)(p.y - 1 - r->map_y) * (r->delta_y * -1);
	}
}

void	ray_init(t_ray *r, t_player p)
{
	r->camera_r = (float)(r->pix_x * 2) / WIN_W - 1;
	r->ray_r = p.angle;
	r->plane_x = 0.66 * sin(r->ray_r);
	r->plane_y = -0.66 * cos(r->ray_r);
	r->hit = 0;
	r->dir_x = cos(r->ray_r) + r->camera_r * r->plane_x;
	r->dir_y = sin(r->ray_r) + r->camera_r * r->plane_y;
	r->delta_x = fabsf(1 / r->dir_x);
	r->delta_y = fabsf(1 / r->dir_y);
	r->map_x = (int)p.x;
	r->map_y = (int)p.y;
}

void	ray_casting(t_cub *cub)
{
	t_ray		r;

	r.pix_x = 1;
	while (r.pix_x < WIN_W)
	{
		ray_init(&r, cub->player);
		side_init(&r, cub->player);
		hit_wall_check(&r, cub);
		draw_ray(&r, cub);
		r.pix_x++;
	}
}
