/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:34:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 15:53:05 by tamighi          ###   ########.fr       */
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

void	blackhole_display(t_cub *cub, int x, int y, t_img img)
{
	int	pix_x;
	int	pix_y;

	pix_x = (x - (cub->player.x - (5 * UNIT))) / 10;
	pix_y = (y - (cub->player.y - (5 * UNIT))) / 10;
	while (pix_x < MINI)
		put_my_pixel(img, pix_x++, pix_y, 0x00FC7462);
}

void	map_elements_display(t_cub *cub, int x, int y, t_img img)
{
	int	pix_x;
	int	pix_y;

	pix_x = (x - (cub->player.x - (5 * UNIT))) / 10;
	pix_y = (y - (cub->player.y - (5 * UNIT))) / 10;
	while (x < 0)
	{
		put_my_pixel(img, pix_x++, pix_y, 0x00FC7462);
		x += (1 * UNIT) / (MINI / 10);
	}
	while (cub->map[y / UNIT][x / UNIT] && pix_x < MINI)
	{
		put_pixel_map(img, pix_x++, pix_y, cub->map[y / UNIT][x / UNIT]);
		x += (1 * UNIT) / (MINI / 10);
	}
	while (pix_x < MINI)
		put_my_pixel(img, pix_x++, pix_y, 0x00FC7462);
}

void	magic_map_displayer(t_cub *cub, int x, int y, t_img img)
{
	while (y < 0)
	{
		blackhole_display(cub, x, y, img);
		y += (1 * UNIT) / (MINI / 10);
	}
	while (cub->map[y / UNIT] && y < cub->player.y + 5 * UNIT)
	{
		map_elements_display(cub, x, y, img);
		y += (1 * UNIT) / (MINI / 10);
	}
	while (y < cub->player.y + 5 * UNIT)
	{
		blackhole_display(cub, x, y, img);
		y += (1 * UNIT) / (MINI / 10);
	}
}

void	display_map(t_cub *cub)
{
	int		y;
	int		x;

	y = cub->player.y - UNIT * 5;
	x = cub->player.x - UNIT * 5;
	magic_map_displayer(cub, x, y, cub->display);
}
