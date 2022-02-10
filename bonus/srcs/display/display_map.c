/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:34:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/10 12:31:27 by tamighi          ###   ########.fr       */
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

	pix_x = MINI_PX_SPACE_X;
	while (x < 0 && ++pix_x)
		x += (float)PX_INDEX_CONV_X;
	while (cub->map[(int)y][(int)x] && pix_x < MINI_PX_X + MINI_PX_SPACE_X)
	{
		put_pixel_map(cub->display, pix_y, pix_x++, cub->map[(int)y][(int)x]);
		x += (float)PX_INDEX_CONV_X;
	}
}

void	put_out_background(t_img img, int px_start_y, int px_start_x)
{
	int	pix_y;
	int	pix_x;

	pix_y = px_start_y;
	while (++pix_y < px_start_y + MINI_PX_Y)
	{
		pix_x = px_start_x - 1;
		while (++pix_x < px_start_x + MINI_PX_X)
			put_my_pixel(img, pix_y, pix_x, OUT_COLOR);
	}
}

void	magic_map_displayer(t_cub *cub, int px_start_y, int px_start_x)
{
	float	y;
	float	x;
	int		pix_y;

	y = cub->player.y - MINI_SIZE_Y / 2;
	x = cub->player.x - MINI_SIZE_X / 2;
	pix_y = px_start_y;
	put_out_background(cub->display, px_start_y, px_start_x);
	while (y < 0)
	{
		y += (float)PX_INDEX_CONV_Y;
		pix_y++;
	}
	while (cub->map[(int)y] && y < cub->player.y + MINI_SIZE_Y / 2)
	{
		map_elements_display(pix_y, y, x, cub);
		y += (float)PX_INDEX_CONV_Y;
		pix_y += 1;
	}
}

void	display_map(t_cub *cub)
{
	int		px_start_y;
	int		px_start_x;

	px_start_y = WIN_H - (MINI_PX_Y + MINI_PX_SPACE_Y);
	px_start_x = MINI_PX_SPACE_X;
	magic_map_displayer(cub, px_start_y, px_start_x);
}
