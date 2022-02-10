/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:30:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/10 13:04:29 by tamighi          ###   ########.fr       */
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

	pix_y = MENUBAR_START_Y;
	img = cub->sprites[MENUBAR][0];
	while (++pix_y < MENUBAR_START_Y + MENUBAR_H)
	{
		pix_x = MENUBAR_START_X;
		tex_y = (float)(pix_y - MENUBAR_START_Y) * ((float)img.h / (float)MENUBAR_H);
		while (++pix_x < MENUBAR_START_X + MENUBAR_W)
		{
			tex_x = (float)(pix_x - MENUBAR_START_X) * ((float)img.w / (float)MENUBAR_W);
			color = get_texture_color(img, (int)tex_y, (int)tex_x);
			put_my_pixel(cub->display, pix_y, pix_x, color);
		}
	}
}
