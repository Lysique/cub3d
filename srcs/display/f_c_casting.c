/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:39:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/03 12:12:16 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_f_c(t_cub *cub, t_ray *r, int y)
{
	int		x;
	int		color;
	char	*dst;

	x = 0;
	while (x < WIN_W)
	{
		r->cell_x = (int)r->floor_x;
		r->cell_y = (int)r->floor_y;
		r->f_c_x = (int)(cub->textures[C].w * (r->floor_x - r->cell_x))
			& (cub->textures[C].w - 1);
		r->f_c_y = (int)(cub->textures[C].h * (r->floor_y - r->cell_y))
			& (cub->textures[C].h - 1);
		r->floor_x += r->fstep_x;
		r->floor_y += r->fstep_y;
		dst = cub->textures[C].addr + (r->f_c_y * cub->textures[C].sizel
				+ r->f_c_x * (cub->textures[C].bpp / 8));
		color = *(unsigned int *)dst;
		put_my_pixel(cub->display, y, x, color);
		dst = cub->textures[F].addr + (r->f_c_y * cub->textures[C].sizel
				+ r->f_c_x * (cub->textures[F].bpp / 8));
		color = *(unsigned int *)dst;
		put_my_pixel(cub->display, WIN_H - y - 1, x, color);
		x++;
	}
}

void	f_c_casting_init(t_cub *cub, t_ray *r, int y)
{
	r->ray_dirx0 = cos(r->ray_r) * -1 - r->plane_x * -1;
	r->ray_dirx1 = cos(r->ray_r) * -1 + r->plane_x * -1;
	r->ray_diry0 = sin(r->ray_r) - r->plane_y;
	r->ray_diry1 = sin(r->ray_r) + r->plane_y;
	r->p = y - WIN_H / 2;
	r->pos_z = 0.5 * WIN_H;
	r->row_dist = r->pos_z / r->p;
	r->fstep_x = r->row_dist * (r->ray_dirx1 - r->ray_dirx0) / WIN_W;
	r->fstep_y = r->row_dist * (r->ray_diry1 - r->ray_diry0) / WIN_W;
	r->floor_x = cub->player.x + r->row_dist * r->ray_dirx0;
	r->floor_y = cub->player.y + r->row_dist * r->ray_diry0;
}

void	f_c_casting(t_cub *cub, t_ray *r)
{
	int	y;

	y = 0;
	while (y < WIN_H / 2)
	{
		f_c_casting_init(cub, r, y);
		draw_f_c(cub, r, y);
		y++;
	}
}
