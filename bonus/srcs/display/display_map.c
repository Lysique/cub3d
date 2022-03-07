/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:34:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/07 09:39:04 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

unsigned int	get_map_color(t_cub *cub, float y, float x, char c)
{
	unsigned int	color;
	int				door;

	door = get_door_index(cub->doors, (int)y, (int)x);
	x -= floor(x);
	x = x / 0.05;
	y -= floor(y);
	y = y / 0.05;
	if (door != -1)
	{
		if (cub->doors[door].open == 0)
			color = get_texture_color(cub->sprites[IMG_MAP][2], (int)y, (int)x);
		else
			color = get_texture_color(cub->sprites[IMG_MAP][3], (int)y, (int)x);
	}
	else if (c == '1')
		color = get_texture_color(cub->sprites[IMG_MAP][0], (int)y, (int)x);
	else if (c == ' ')
		color = OUT_COLOR;
	else
		color = get_texture_color(cub->sprites[IMG_MAP][1], (int)y, (int)x);
	return (color);
}

void	map_elements_display(int pix_y, float y, float x, t_cub *cub)
{
	int				pix_x;
	unsigned int	color;

	pix_x = MINI_PX_SPACE_X;
	while (x < 0 && ++pix_x)
		x += (float)PX_INDEX_CONV_X;
	while (cub->map[(int)y][(int)x] && pix_x < MINI_PX_X + MINI_PX_SPACE_X)
	{
		color = get_map_color(cub, y, x, cub->map[(int)y][(int)x]);
		put_my_pixel(cub->display, pix_y, pix_x++, color);
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
	t_img	img;

	img = cub->sprites[MAPBAR][0];
	draw_img(cub, img, MAPBAR_START_Y, MAPBAR_START_X);
	px_start_y = WIN_H - (MINI_PX_Y + MINI_PX_SPACE_Y);
	px_start_x = MINI_PX_SPACE_X;
	magic_map_displayer(cub, px_start_y, px_start_x);
}
