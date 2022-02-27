/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:10:17 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 11:47:45 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	order_sprites(t_cub *cub)
{
	int		i;
	float	dist;
	float	dist2;
	t_spr	spr;

	i = -1;
	dist = -1;
	while (cub->sprs[++i].to_draw != -1)
	{
		dist2 = (cub->player.x - cub->sprs[i].x) * (cub->player.x - cub->sprs[i].x)
			+ (cub->player.y - cub->sprs[i].y) * (cub->player.y - cub->sprs[i].y);
		if (dist != -1 && dist2 > dist)
		{
			dist = -1;
			spr = cub->sprs[i - 1];
			cub->sprs[i - 1] = cub->sprs[i];
			cub->sprs[i] = spr;
			i = -1;
		}
		else
			dist = dist2;
	}
}

void	init_standard_en_spr(t_cub *cub, int j, t_ray *r, t_en en)
{
	t_spr	s;

	s.tex = en.img;
	s.offset = en.offset;
	s.to_draw = 1;
	s.x = en.x;
	s.y = en.y;
	s.sprite_x = s.x - cub->player.x;
	s.sprite_y = s.y - cub->player.y;
	s.invdet = 1 / (sin(r->p_angle) * -1 * r->cam_plane_x
			- cos(r->p_angle) * r->cam_plane_y);
	s.transf_x = s.invdet * (sin(r->p_angle) * -1 * s.sprite_x
			- cos(r->p_angle) * s.sprite_y);
	s.transf_y = s.invdet * (r->cam_plane_y * -1 * s.sprite_x
			+ r->cam_plane_x * s.sprite_y);
	s.sprite_screen_x = (int)(WIN_W / 2) *(1 + s.transf_x / s.transf_y);
	s.sprite_height = abs((int)(WIN_H / s.transf_y)) / en.div;
	s.sprite_width = abs((int)(WIN_H / s.transf_y));
	s.draw_start = s.sprite_height * -1 / 2 + WIN_H / 2 + (int)(s.offset / s.transf_y);
	if (s.draw_start < 0)
		s.draw_start = 0;
	s.draw_end = s.sprite_height / 2 + WIN_H / 2 + (int)(s.offset / s.transf_y);
	if (s.draw_end > WIN_H - 1)
		s.draw_end = WIN_H - 1;
	cub->sprs[j] = s;
}

void	sprites_init(t_ray *r, t_cub *cub)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (cub->en[++i].action != -1)
	{
		init_standard_en_spr(cub, j, r, cub->en[i]);
		j++;
	}
	order_sprites(cub);
}
