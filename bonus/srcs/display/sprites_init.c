/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:10:17 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/23 13:20:42 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	order_sprites(t_cub *cub)
{
	int		i;
	float	dist;
	float	dist2;
	t_en	en;

	i = -1;
	dist = -1;
	while (cub->en[++i].action != -1)
	{
		dist2 = (cub->player.x - cub->en[i].x) * (cub->player.x - cub->en[i].x)
			+ (cub->player.y - cub->en[i].y) * (cub->player.y - cub->en[i].y);
		if (dist != -1 && dist2 > dist)
		{
			dist = -1;
			en = cub->en[i - 1];
			cub->en[i - 1] = cub->en[i];
			cub->en[i] = en;
			i = -1;
		}
		else
			dist = dist2;
	}
}

void	init_struct(t_en *en, t_ray *r, t_cub *cub)
{
	t_spr	s;

	s.tex = en->img;
	s.sprite_x = en->x - cub->player.x;
	s.sprite_y = en->y - cub->player.y;
	s.invdet = 1 / (sin(r->p_angle) * -1 * r->cam_plane_x
			- cos(r->p_angle) * r->cam_plane_y);
	s.transf_x = s.invdet * (sin(r->p_angle) * -1 * s.sprite_x
			- cos(r->p_angle) * s.sprite_y);
	s.transf_y = s.invdet * (r->cam_plane_y * -1 * s.sprite_x
			+ r->cam_plane_x * s.sprite_y);
	s.sprite_screen_x = (int)(WIN_W / 2) *(1 + s.transf_x / s.transf_y);
	s.sprite_height = abs((int)(WIN_H / s.transf_y)) / 1.5;
	s.sprite_width = abs((int)(WIN_H / s.transf_y));
	s.draw_start = s.sprite_height * -1 / 2 + WIN_H / 2 + (int)(en->offset / s.transf_y);
	if (s.draw_start < 0)
		s.draw_start = 0;
	s.draw_end = s.sprite_height / 2 + WIN_H / 2 + (int)(en->offset / s.transf_y);
	if (s.draw_end > WIN_H - 1)
		s.draw_end = WIN_H - 1;
	en->s = s;
}

void	sprites_init(t_ray *r, t_cub *cub)
{
	int		i;

	i = -1;
	while (cub->en[++i].action != -1)
		init_struct(&cub->en[i], r, cub);
	order_sprites(cub);
}
