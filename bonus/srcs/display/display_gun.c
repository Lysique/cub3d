/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:42:54 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 12:04:44 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void display_gun_sight(t_cub *cub)
{
	int	x;
	int	y;

	x = WIN_W / 2 - 2;
	while (x < WIN_W / 2 + 2)
	{
		y = WIN_H / 2 - 2;
		while (y < WIN_H / 2 + 2)
			put_my_pixel(cub->display, y++, x, RED);
		x++;
	}
}

// void	draw_gun(t_cub *cub, t_img img, int start_y, int start_x)
// {
// 	int				pix_x;
// 	int				pix_y;
// 	float			tex_x;
// 	float			tex_y;
// 	unsigned int	color;

// 	pix_x = -1;
// 	while (++pix_x < SIZE_GUN_X * img.w)
// 	{
// 		pix_y = -1;
// 		while (++pix_y < SIZE_GUN_Y * img.h)
// 		{
// 			tex_y = (float)pix_y / (float)SIZE_GUN_Y;
// 			tex_x = (float)pix_x / (float)SIZE_GUN_X;
// 			color = get_texture_color(img, (int)tex_y, (int)tex_x);
// 			put_my_pixel(cub->display, pix_y + start_y, pix_x + start_x, color);
// 		}
// 	}
// }

void	draw_gun(t_cub *cub, t_img img, int start_y, int start_x)
{
	int				pix_x;
	int				pix_y;
	float			tex_x;
	float			tex_y;
	unsigned int	color;

	pix_x = -1;
	tex_x = 0;
	while (++pix_x < img.w)
	{
		pix_y = -1;
		tex_y = 0;
		while (++pix_y < img.h)
		{
			tex_y = (float)pix_y;
			color = get_texture_color(img, (int)tex_y, (int)tex_x);
			put_my_pixel(cub->display, pix_y + start_y, pix_x + start_x, color);
		}
		tex_x = (float)pix_x;
	}
}

void	display_gun(t_cub *cub)
{
	int		start_x;
	int		start_y;
	t_img	img;

	img = cub->sprites[cub->gun_type + 2][cub->gun[cub->gun_type].sprite];
	start_x = POS_GUN_X - img.w / 2;
	start_y = POS_GUN_Y - img.h;
	draw_gun(cub, img, start_y, start_x);
	display_gun_sight(cub);
}
