/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:42:54 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/07 10:59:40 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_walls(t_cub *cub, t_ray *r)
{
	int		color;

	while (r->draw_start < r->draw_end)
	{
		r->tex_y = (int)r->tex_pos;
		r->tex_pos += r->tex_stepy;
		color = get_texture_color(r->tex, r->tex_x, r->tex_y);
		put_my_pixel(cub->display, r->draw_start++, r->pix_x, color);
	}
}

void	init_draywing_variables(t_ray *r, t_cub *cub)
{
	if (r->side == WE_EA)
		r->wall_dist = r->side_x - r->delta_x;
	else
		r->wall_dist = r->side_y - r->delta_y;
	r->line_h = (int)(WIN_H / r->wall_dist);
	r->draw_start = r->line_h * -1 / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_h / 2 + WIN_H / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
	if (r->side == SO_NO)
		r->wall_x = cub->player.x + r->wall_dist * r->dir_x;
	else
		r->wall_x = cub->player.y + r->wall_dist * (r->dir_y * -1);
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * (float)r->tex.w);
	r->tex_stepy = (float)r->tex.h / r->line_h;
	r->tex_pos = (r->draw_start - WIN_H / 2 + r->line_h / 2) * r->tex_stepy;
}

void	init_texture(t_ray *r, t_cub *cub)
{
	if (r->side == SO_NO && r->step_y == -1)
		r->tex = cub->textures[SO];
	else if (r->side == SO_NO)
		r->tex = cub->textures[NO];
	else if (r->side == WE_EA && r->step_x == 1)
		r->tex = cub->textures[WE];
	else
		r->tex = cub->textures[EA];
}

void	draw_ray(t_ray *r, t_cub *cub)
{
	init_texture(r, cub);
	init_draywing_variables(r, cub);
	draw_walls(cub, r);
}
