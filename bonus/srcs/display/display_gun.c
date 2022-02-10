/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:42:54 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/09 15:05:14 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_gun(t_cub *cub, t_img img, int start_y, int start_x)
{
	int				pix_x;
	int				pix_y;
	unsigned int	color;

	pix_x = -1;
	while (++pix_x < img.w * 2)
	{
		pix_y = -1;
		while (++pix_y < img.h * 2)
		{
			color = get_texture_color(img, pix_y / 2, pix_x / 2);
			if (color != 0xFF000000)
				put_my_pixel(cub->display, pix_y + start_y, pix_x + start_x, color);
		}
	}
}

void	display_gun(t_cub *cub)
{
	int		start_x;
	int		start_y;
	t_img	img;

	img = cub->sprites[cub->gun_type + 2][cub->gun[cub->gun_type].sprite];
	start_x = WIN_W / 2 - img.w;
	start_y = WIN_H - MENUBAR_H - img.h * 2;
	draw_gun(cub, img, start_y, start_x);
}
