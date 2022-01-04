/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:34:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/04 13:52:03 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	put_pixel_map(t_img img, int x, int y, char c)
{
	if (c == '1')
		put_my_pixel(img, x, y, 0x00000000);
	else if (c == '0')
		put_my_pixel(img, x, y, 0x0000FF00);
}

void	blackhole_display(t_cub *cub, float x, float y, t_img img)
{
	int	pix_x;
	int	pix_y;

	pix_x = (x - (cub->player.x - 5)) * MINI / 10;
	pix_y = (y - (cub->player.y - 5)) * MINI / 10;
	while (pix_x < MINI)
		put_my_pixel(img, pix_x++, pix_y, 0x00FC7462);
}

void	map_elements_display(t_cub *cub, float x, float y, t_img img)
{
	int	pix_x;
	int	pix_y;

	pix_x = (x - (cub->player.x - 5)) * MINI / 10;
	pix_y = (y - (cub->player.y - 5)) * MINI / 10;
	while (x < 0)
	{
		put_my_pixel(img, pix_x++, pix_y, 0x00FC7462);
		x += (float)1 / (MINI / 10);
	}
	while (cub->map[(int)y][(int)x] && pix_x < MINI)
	{
		put_pixel_map(img, pix_x++, pix_y, cub->map[(int)y][(int)x]);
		x += (float)1 / (MINI / 10);
	}
	while (pix_x < MINI)
		put_my_pixel(img, pix_x++, pix_y, 0x00FC7462);
}

void	magic_map_displayer(t_cub *cub, float x, float y, t_img img)
{
	while (y < 0)
	{
		blackhole_display(cub, x, y, img);
		y += (float)1 / (MINI / 10);
	}
	while (cub->map[(int)y] && y < cub->player.y + 5)
	{
		map_elements_display(cub, x, y, img);
		y += (float)1 / (MINI / 10);
	}
	while (y < cub->player.y + 5)
	{
		blackhole_display(cub, x, y, img);
		y += (float)1 / (MINI / 10);
	}
}

void	display_map(t_cub *cub)
{
	float	y;
	float	x;

	y = cub->player.y - 5;
	x = cub->player.x - 5;
	magic_map_displayer(cub, x, y, cub->display);
}
