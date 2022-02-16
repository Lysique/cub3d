/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_ennemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:58:09 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/16 10:31:15 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_walls(t_cub *cub, t_ray *r);

void	en_ray_init(t_ray *r, t_cub *cub, t_en en)
{
	float	dir;
	float	diff_x;
	float	diff_y;

	r->tex = en.img;
	diff_x = (en.x - cub->player.x);
	diff_y = (en.y - cub->player.y); 
	r->wall_dist = sqrtf((diff_x) * (diff_x) + (diff_y) * (diff_y));
	r->line_h = (int)(WIN_H / r->wall_dist);
	r->draw_start = r->line_h * -1 / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_h / 2 + WIN_H / 2;
	if (r->draw_end > WIN_H)
		r->draw_end = WIN_H;
	if (r->dir_x > 0 && r->dir_y < 0)
		dir = r->dir_x * -1 + (r->dir_y * -1);
	else
		dir = r->dir_x + (r->dir_y * -1);
	dir *= r->wall_dist;
	if (r->dir_x > 0 && r->dir_y < 0)
		r->wall_x = (diff_x) + (diff_y) * -1 - (r->dir_x * r->wall_dist) + (r->dir_y * -1 * r->wall_dist) + 0.5;
	else if (r->dir_x < 0 && r->dir_y > 0)
		r->wall_x = (diff_x) * -1 + (diff_y) + (r->dir_x * r->wall_dist) - (r->dir_y * -1 * r->wall_dist) + 0.5;
	else
		r->wall_x = (cub->player.x + en.x) + (cub->player.y + en.y) + dir + 0.5;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = r->wall_x * (float)r->tex.w;
	r->tex_stepy = (float)r->tex.h / r->line_h;
	r->tex_y = (r->draw_start - WIN_H / 2 + r->line_h / 2) * r->tex_stepy;
	r->tex_stepy *= OPTIMISATION;
	draw_walls(cub, r);
}

void	ray_cast_ennemy(t_ray *r, t_cub *cub)
{
	int i;

	i = is_ennemy(cub->en, r->map_y, r->map_x);
	en_ray_init(r, cub, cub->en[i]);
}
