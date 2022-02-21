/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:30:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/13 16:32:08 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

// void	draw_menu(t_cub *cub, t_img img, int pix_y, int pix_x)
// {
// 	float			tex_x;
// 	float			tex_y;
// 	unsigned int	color;

// 	while (++pix_y < MENUBAR_START_Y + MENUBAR_H)
// 	{
// 		pix_x = MENUBAR_START_X;
// 		tex_y = (float)(pix_y - MENUBAR_START_Y)
// 			*((float)img.h / (float)MENUBAR_H);
// 		while (++pix_x < MENUBAR_START_X + MENUBAR_W)
// 		{
// 			tex_x = (float)(pix_x - MENUBAR_START_X)
// 				*((float)img.w / (float)MENUBAR_W);
// 			color = get_texture_color(img, (int)tex_y, (int)tex_x);
// 			put_my_pixel(cub->display, pix_y, pix_x, color);
// 		}
// 	}
// }

void	draw_text(t_cub *cub, int start_y, int start_x, char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		if (text[i] >= '0' && text[i] <= '9')
		{
			draw_img(cub, cub->sprites[POLICE][text[i] - '0'], start_y, start_x);
			start_x += cub->sprites[POLICE][text[i] - '0'].w;
		}
		i++;
	}
}

void	display_menu(t_cub *cub)
{
	t_img		img;

	img = cub->sprites[MENUBAR][0];
	draw_img(cub, img, MENUBAR_START_Y, MENUBAR_START_X);
	draw_text(cub, POS_NB_BULLET_Y, POS_NB_BULLET_X, ft_itoa(cub->gun[cub->gun_type].bullets));
	//draw_text(cub, POS_NB_BULLET_Y, POS_NB_BULLET_X, "1");
}
