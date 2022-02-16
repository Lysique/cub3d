/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:39:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/14 13:41:25 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_f_c(t_cub *cub, t_ray *r, int y)
{
	int		x;
	int		color;

	x = 0;
	while (x < WIN_W - (OPTIMISATION - 1))
	{
		r->tex_x = (cub->textures[C].w * (r->floor_x - (int)r->floor_x));
		r->tex_y = (cub->textures[C].h * (r->floor_y - (int)r->floor_y));
		color = get_texture_color(cub->textures[C],
				(int)r->tex_y, (int)r->tex_x);
		optimisation_pixel_put(cub->display, y, x, color);
		r->tex_x = (cub->textures[F].w * (r->floor_x - (int)r->floor_x));
		r->tex_y = (cub->textures[F].h * (r->floor_y - (int)r->floor_y));
		color = get_texture_color(cub->textures[F],
				(int)r->tex_y, (int)r->tex_x);
		optimisation_pixel_put(cub->display, WIN_H
			- y - OPTIMISATION, x, color);
		r->floor_x += r->tex_stepx;
		r->floor_y += r->tex_stepy;
		x += OPTIMISATION;
	}
}

void	f_c_casting_init(t_cub *cub, t_ray *r, int y)
{
	r->ray_r = cub->player.angle;
	r->plane_x = 0.66 * sin(r->ray_r);
	r->plane_y = -0.66 * cos(r->ray_r);
	r->dir_x = cos(r->ray_r) * -1 - r->plane_x * -1;
	r->dir2_x = cos(r->ray_r) * -1 + r->plane_x * -1;
	r->dir_y = sin(r->ray_r) - r->plane_y;
	r->dir2_y = sin(r->ray_r) + r->plane_y;
	r->p = y - WIN_H / 2;
	r->row_dist = (float)(0.5 * WIN_H) / r->p;
	r->tex_stepx = (r->row_dist * (r->dir2_x - r->dir_x)
			/ WIN_W) * OPTIMISATION;
	r->tex_stepy = (r->row_dist * (r->dir2_y - r->dir_y)
			/ WIN_W) * OPTIMISATION;
	r->floor_x = cub->player.x + r->row_dist * r->dir_x;
	r->floor_y = cub->player.y + r->row_dist * r->dir_y;
}

void	f_c_casting(t_cub *cub)
{
	int		y;
	t_ray	r;

	y = 0;
	r.pix_x = 0;
	while (y < WIN_H / 2 - (OPTIMISATION - 1))
	{
		f_c_casting_init(cub, &r, y);
		draw_f_c(cub, &r, y);
		y += OPTIMISATION;
	}
}
