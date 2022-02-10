/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:30:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/09 15:35:07 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	display_menu(t_cub *cub)
{
	int			pix_x;
	int			pix_y;
	float		tex_x;
	float		tex_y;
	t_img			img;
	unsigned int	color;

	pix_y = WIN_H - MENUBAR_H;
	img = cub->sprites[MENUBAR][0];
	while (++pix_y < WIN_H)
	{
		pix_x = MINI_PX + 1.5 * PIX_SPACE;
		while (++pix_x < WIN_W)
		{
			tex_x = (float)img.w / (float)(WIN_W - (MINI_PX + 1.5 * PIX_SPACE)) * (pix_x - (MINI_PX + 1.5 * PIX_SPACE));
			tex_y = (float)img.h / (float)(MENUBAR_H) * (pix_y - (WIN_H -MENUBAR_H));
			color = get_texture_color(img, (int)tex_y, (int)tex_x);
			put_my_pixel(cub->display, pix_y, pix_x, color);
		}
	}
}
