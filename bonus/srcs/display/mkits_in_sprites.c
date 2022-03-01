/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkits_in_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:46:01 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 15:59:31 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	init_mkit_spr(t_cub *cub, int j, t_ray *r, t_mkit mkit)
{
	t_spr	s;

	s.tex = mkit.img;
	s.offset = 300;
	s.to_draw = 1;
	s.x = mkit.x;
	s.y = mkit.y;
	s.sprite_x = s.x - cub->player.x;
	s.sprite_y = s.y - cub->player.y;
	s.invdet = 1 / (sin(r->p_angle) * -1 * r->cam_plane_x
			- cos(r->p_angle) * r->cam_plane_y);
	s.transf_x = s.invdet * (sin(r->p_angle) * -1 * s.sprite_x
			- cos(r->p_angle) * s.sprite_y);
	s.transf_y = s.invdet * (r->cam_plane_y * -1 * s.sprite_x
			+ r->cam_plane_x * s.sprite_y);
	s.sprite_screen_x = (int)(WIN_W / 2) *(1 + s.transf_x / s.transf_y);
	s.sprite_height = abs((int)(WIN_H / s.transf_y)) / 3;
	s.sprite_width = abs((int)(WIN_H / s.transf_y)) / 3;
	s_draw_start_end_fct(&s);
	cub->sprs[j] = s;
}

void	mkits_in_sprites(t_cub *cub, int *j, t_ray *r)
{
	int	i;

	i = -1;
	while (cub->mkits[++i].active != -1)
	{
		if (cub->mkits[i].active)
			init_mkit_spr(cub, (*j)++, r, cub->mkits[i]);
	}
}
