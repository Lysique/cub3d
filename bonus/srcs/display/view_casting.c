/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:09:01 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/19 16:57:18 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	side_init(t_ray *r, float p_x, float p_y)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_x = (float)(p_x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->side_x = (float)(p_x - 1 - r->map_x) * r->delta_x * -1;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_y = (float)(p_y - r->map_y) * r->delta_y ;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (float)(p_y - 1 - r->map_y) * r->delta_y * -1;
	}
}

void	cast_ray(t_ray *r, t_cub *cub)
{
	r->cam_r = 2 * (float)r->pix_screen_x / (WIN_W - 1) - 1;
	r->dir_x = cos(r->p_angle) + r->cam_r * r->cam_plane_x;
	r->dir_y = (sin(r->p_angle) * -1) + r->cam_r * r->cam_plane_y;
	r->map_x = (int)cub->player.x;
	r->map_y = (int)cub->player.y;
	r->delta_x = fabsf(1 / r->dir_x);
	r->delta_y = fabsf(1 / r->dir_y);
	side_init(r, cub->player.x, cub->player.y);
	hit_wall_check(r, cub);
}

void	ray_init(t_ray *r, t_cub *cub)
{
	r->p_angle = cub->player.angle;
	r->fov = 0.66;
	r->cam_plane_x = r->fov * sin(r->p_angle);
	r->cam_plane_y = r->fov * cos(r->p_angle);
}

void	view_casting(t_cub *cub)
{
	t_ray	r;

	r.pix_screen_x = 0;
	ray_init(&r, cub);
	f_c_casting(&r, cub);
	sprites_init(&r, cub);
	while (r.pix_screen_x < WIN_W)
	{
		cast_ray(&r, cub);
		r.pix_screen_x += OPTI;
	}
}
