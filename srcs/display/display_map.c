/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:34:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/25 13:22:09 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	put_pixel_map(t_img img, int pix_x, int pix_y, char c)
{
	if (c == '1')
		put_my_pixel(img, pix_x, pix_y, WALL_COLOR);
	else if (c == '0')
		put_my_pixel(img, pix_x, pix_y, IN_COLOR);
	else if (c == ' ') 
		put_my_pixel(img, pix_x, pix_y, SPACE_COLOR);
}

void	map_elements_display(int pix_y, float x, float y, t_cub *cub)
{
	int	pix_x;

	pix_x = 0;
	while (x < 0 && ++pix_x)
		x += (float)PX_INDEX_CONV;
	while (cub->map[(int)y][(int)x] && pix_x < MINI_PX)
	{
		put_pixel_map(cub->display, pix_x++, pix_y, cub->map[(int)y][(int)x]);
		x += (float)PX_INDEX_CONV;
	}
}

void	put_out_background(t_img img)
{
	int	pix_x;
	int	pix_y;

	pix_x = -1;
	pix_y = -1;
	while (++pix_y < MINI_PX)
	{
		while (++pix_x < MINI_PX)
			put_my_pixel(img, pix_x, pix_y, OUT_COLOR);
		pix_x = -1;
	}
}

void	magic_map_displayer(t_cub *cub, float x, float y)
{
	int	pix_y;

	pix_y = 0;
	put_out_background(cub->display);
	while (y < 0)
	{
		y += (float)PX_INDEX_CONV;
		pix_y++;
	}
	while (cub->map[(int)y] && y < cub->player.y + MINI_SIZE / 2)
	{
		map_elements_display(pix_y, x, y, cub);
		y += (float)PX_INDEX_CONV;
		pix_y += 1;
	}
}

void	display_map(t_cub *cub)
{
	float	y;
	float	x;

	y = cub->player.y - MINI_SIZE / 2;
	x = cub->player.x - MINI_SIZE / 2;
	magic_map_displayer(cub, x, y);
}
