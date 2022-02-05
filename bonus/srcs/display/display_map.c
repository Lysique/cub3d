/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:34:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/05 13:11:32 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	put_pixel_map(t_img img, int pix_y, int pix_x, char c)
{
	if (c == '1')
		put_my_pixel(img, pix_y, pix_x, WALL_COLOR);
	else if (c == '0')
		put_my_pixel(img, pix_y, pix_x, IN_COLOR);
	else if (c == ' ')
		put_my_pixel(img, pix_y, pix_x, SPACE_COLOR);
}

void	map_elements_display(int pix_y, float y, float x, t_cub *cub)
{
	int	pix_x;

	pix_x = 0;
	while (x < 0 && ++pix_x)
		x += (float)PX_INDEX_CONV;
	while (cub->map[(int)y][(int)x] && pix_x < MINI_PX)
	{
		put_pixel_map(cub->display, pix_y, pix_x++, cub->map[(int)y][(int)x]);
		x += (float)PX_INDEX_CONV;
	}
}

void	put_out_background(t_img img)
{
	int	pix_x;
	int	pix_y;

	pix_x = -1;
	pix_y = WIN_H - MINI_PX - 1;
	while (++pix_y < WIN_H)
	{
		while (++pix_x < MINI_PX)
			put_my_pixel(img, pix_y, pix_x, OUT_COLOR);
		pix_x = -1;
	}
}

void	magic_map_displayer(t_cub *cub, float y, float x)
{
	int	pix_y;

	pix_y = WIN_H - MINI_PX - 1;
	put_out_background(cub->display);
	while (y < 0)
	{
		y += (float)PX_INDEX_CONV;
		pix_y++;
	}
	while (cub->map[(int)y] && y < cub->player.y + MIDMINI)
	{
		map_elements_display(pix_y, y, x, cub);
		y += (float)PX_INDEX_CONV;
		pix_y += 1;
	}
}

void	display_map(t_cub *cub)
{
	float	y;
	float	x;

	y = cub->player.y - MIDMINI;
	x = cub->player.x - MIDMINI;
	magic_map_displayer(cub, y, x);
}
