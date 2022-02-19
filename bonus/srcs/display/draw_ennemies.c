/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ennemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:06:12 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/19 15:05:56 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_ennemies(t_ray *r, t_cub *cub)
{
	unsigned int	color;
	t_spr			s;
	int				i;

	i = -1;
	while (cub->en[++i].action != -1)
	{
		s = cub->en[i].s;
		if (s.transf_y <= 0 || s.transf_y >= r->perp_wall_dist)
			continue ;
		s.tex_x = (int)((256 * (r->pix_screen_x
						- (s.sprite_width * -1 / 2 + s.sprite_screen_x))
					* s.tex.w / s.sprite_width) / 256);
		while (s.draw_start < s.draw_end)
		{
			s.d = (s.draw_start - (int)(200.0 / s.transf_y)) * 256 - WIN_H * 128 + s.sprite_height * 128;
			s.tex_y = ((s.d * s.tex.h) / s.sprite_height) / 256;
			color = get_texture_color(s.tex, s.tex_y, s.tex_x);
			optimisation_pixel_put(cub->display,
				s.draw_start, r->pix_screen_x, color);
			s.draw_start += OPTI;
		}
	}
}