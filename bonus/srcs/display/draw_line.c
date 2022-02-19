/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:15:48 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/19 13:52:12 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	line_to_screen(t_ray *r, t_cub *cub)
{
	unsigned int	color;

	while (r->draw_start < r->draw_end)
	{
		r->tex_y += r->tex_stepy;
		color = get_texture_color(r->tex, (int)r->tex_y, (int)r->tex_x);
		optimisation_pixel_put(cub->display,
			r->draw_start, r->pix_screen_x, color);
		r->draw_start += OPTI;
	}
	draw_ennemies(r, cub);
}

void	line_init(t_ray *r, t_cub *cub)
{
	if (r->side == SO_NO)
		r->perp_wall_dist = r->side_y - r->delta_y;
	else
		r->perp_wall_dist = r->side_x - r->delta_x;
	r->line_h = (int)(WIN_H / r->perp_wall_dist);
	r->draw_start = r->line_h * -1 / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_h / 2 + WIN_H / 2;
	if (r->draw_end > WIN_H)
		r->draw_end = WIN_H;
	if (r->side == SO_NO)
		r->wall_x = cub->player.x + r->perp_wall_dist * r->dir_x;
	else
		r->wall_x = cub->player.y + r->perp_wall_dist * r->dir_y;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = r->wall_x * (float)r->tex.w;
	r->tex_stepy = (float)r->tex.h / r->line_h;
	r->tex_y = (r->draw_start - WIN_H / 2 + r->line_h / 2) * r->tex_stepy;
	r->tex_stepy *= OPTI;
}

void	text_init(t_ray *r, t_cub *cub)
{
	int	door;

	door = get_door_index(cub->doors, r->map_y, r->map_x);
	if (door != -1)
		r->tex = cub->sprites[DOOR][cub->doors[get_door_index(cub->doors,
				r->map_y, r->map_x)].sprite];
	else if (r->side == SO_NO && r->step_y == -1)
		r->tex = cub->textures[SO];
	else if (r->side == SO_NO)
		r->tex = cub->textures[NO];
	else if (r->side == WE_EA && r->step_x == 1)
		r->tex = cub->textures[WE];
	else
		r->tex = cub->textures[EA];
}

void	draw_line(t_ray *r, t_cub *cub)
{
	text_init(r, cub);
	line_init(r, cub);
	line_to_screen(r, cub);
}
