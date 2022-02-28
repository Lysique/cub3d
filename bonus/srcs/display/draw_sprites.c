/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:06:12 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 14:44:11 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

int	spr_not_to_draw(t_spr s, t_ray *r)
{
	if (s.to_draw == 0)
		return (1);
	if (s.transf_y <= 0 || s.transf_y >= r->perp_wall_dist
		|| s.tex_x < 0 || s.tex_x >= s.tex.w)
		return (1);
	if (s.sprite_screen_x > 1920 || s.sprite_screen_x < 0)
		return (1);
	return (0);
}

void	draw_sprites(t_ray *r, t_cub *cub)
{
	unsigned int	color;
	t_spr			s;
	int				i;

	i = -1;
	while (cub->sprs[++i].to_draw != -1)
	{
		s = cub->sprs[i];
		s.tex_x = (int)((256 * (r->pix_screen_x
						- (s.sprite_width * -1 / 2 + s.sprite_screen_x))
					* s.tex.w / s.sprite_width) / 256);
		if (spr_not_to_draw(s, r))
			continue ;
		while (s.draw_start < s.draw_end)
		{
			s.d = (s.draw_start - (int)(s.offset / s.transf_y))
				* 256 - WIN_H * 128 + s.sprite_height * 128;
			s.tex_y = ((s.d * s.tex.h) / s.sprite_height) / 256;
			color = get_texture_color(s.tex, s.tex_y, s.tex_x);
			optimisation_pixel_put(cub->display,
				s.draw_start, r->pix_screen_x, color);
			s.draw_start += OPTI;
		}
	}
}
