/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:01:30 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 12:58:59 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_f_c(t_cub *cub, t_ray *r, int y)
{
	int		x;
	int		color;

	x = 0;
	while (x < WIN_W)
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
			- y - OPTI, x, color);
		r->floor_x += r->tex_stepx;
		r->floor_y += r->tex_stepy;
		x += OPTI;
	}
}

void	f_c_casting_init(t_cub *cub, t_ray *r, int y)
{
	r->p = y - WIN_H / 2;
	r->row_dist = (float)(0.5 * WIN_H) / r->p;
	r->tex_stepx = (r->row_dist * (r->dir2_x - r->dir_x)
			/ WIN_W) * OPTI;
	r->tex_stepy = (r->row_dist * (r->dir2_y - r->dir_y)
			/ WIN_W) * OPTI;
	r->floor_x = cub->player.x + r->row_dist * r->dir_x;
	r->floor_y = cub->player.y + r->row_dist * r->dir_y;
}

void	draw_bg(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_H)
	{
		j = -1;
		while (++j < WIN_W)
			put_my_pixel(cub->display, i, j, BLACK);
	}
}

void	f_c_casting(t_ray *r, t_cub *cub)
{
	int		y;

	y = 0;
	if (0)
		draw_bg(cub);
	else
	{
		r->dir_x = cos(r->p_angle) * -1 - r->cam_plane_x * -1;
		r->dir2_x = cos(r->p_angle) * -1 + r->cam_plane_x * -1;
		r->dir_y = sin(r->p_angle) + r->cam_plane_y;
		r->dir2_y = sin(r->p_angle) - r->cam_plane_y;
		while (y < WIN_H / 2)
		{
			f_c_casting_init(cub, r, y);
			draw_f_c(cub, r, y);
			y += OPTI;
		}
	}
}
