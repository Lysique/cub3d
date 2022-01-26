/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:14:29 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/26 15:38:32 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_line_ray(t_cub *cub, t_ray *r, int color)
{
	int	y;

	y = 1;
	while (y < r->draw_start)
		put_my_pixel(cub->display, r->pix_x, y++, BLUE);
	while (r->draw_start < r->draw_end && y++)
		put_my_pixel(cub->display, r->pix_x, r->draw_start++, color);
	while (y < WIN_H)
		put_my_pixel(cub->display, r->pix_x, y++, BLUE);
}

void	draw_ray(t_ray *r, t_cub *cub)
{
	r->line_h = (int)(WIN_H / r->wall_dist);
	r->draw_start = r->line_h * -1 / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_h / 2 + WIN_H / 2;
	if (r->draw_start >= WIN_H)
		r->draw_start = WIN_H - 1;
	draw_line_ray(cub, r, RED);
}

void	hit_wall_check(t_ray *r, t_cub *cub)
{
	while (r->hit == 0)
	{
		if (r->side_y < r->side_x)
		{
			r->side_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		else
		{
			r->side_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		if (cub->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
	printf("map_y : %d, map_x : %d = %s\n", r->map_y, r->map_x, cub->map[r->map_y]);
	if (r->side == 0)
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
		r->side_x = (float)(p.x + 1 - r->map_x) * r->delta_x;
	}
	if (r->dir_y > 0)
	{
		r->step_y = -1;
		r->side_y = (float)(p.y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->side_y = (float)(p.y + 1 - r->map_y) * r->delta_y;
	}
//	printf("delta_x %f, delta_y %f, side_x %f, side_y %f\n", r->delta_x, r->delta_y, r->side_x, r->side_y);
}

void	ray_init(t_ray *r, t_player p)
{
	r->camera_x = 2 * r->pix_x / WIN_W - 1;
	r->ray_r = p.angle;
	r->hit = 0;
	r->dir_x = sin(p.angle);
	r->dir_y = cos(p.angle) * (0.66 + r->camera_x);
	r->delta_x = fabsf(1 / r->dir_x);
	r->delta_y = fabsf(1 / r->dir_y);
	r->map_x = (int)p.x;
	r->map_y = (int)p.y;
	printf("Rad : %f, sin : %f, cos : %f\n", p.angle, r->dir_x, r->dir_y);
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
