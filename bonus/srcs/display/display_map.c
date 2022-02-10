/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:34:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/10 08:38:57 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	ft_draw_line(t_img img, t_cub *cub)
{
	float	bx;
	float	by;
	float	d;
	float	pente;

	bx = cos(cub->player.angle);
	by = sin(cub->player.angle);
	d = 0;
	if (bx < 0.05 && bx > -0.05)
		bx = 0.05;
	pente = by / bx;
	while (sqrtf(((d * pente) * (d * pente)) + d * d) <= 20)
	{
		put_my_pixel(img, (WIN_H - MINI_PX / 2 - d
			* pente) - PIX_SPACE, (MINI_PX / 2 + d) + PIX_SPACE, RED);
		if (0 > bx)
			d -= .1;
		else
			d += .1;
	}
}

void	display_char(t_cub *cub)
{
	int		pix_x;
	int		pix_y;
	t_img	img;

	img = cub->display;
	pix_y = (WIN_H - MINI_PX / 2 - 5) - PIX_SPACE;
	while (pix_y < (WIN_H - MINI_PX / 2 + 5) - PIX_SPACE)
	{
		pix_x = (MINI_PX / 2 - 5) + PIX_SPACE;
		while (pix_x < (MINI_PX / 2 + 5) + PIX_SPACE)
			put_my_pixel(img, pix_y, pix_x++, BLUE);
		pix_y++;
	}
	ft_draw_line(img, cub);
}

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

	pix_x = PIX_SPACE;
	while (x < 0 && ++pix_x)
		x += (float)PX_INDEX_CONV;
	while (cub->map[(int)y][(int)x] && pix_x < MINI_PX + PIX_SPACE)
	{
		put_pixel_map(cub->display, pix_y, pix_x++, cub->map[(int)y][(int)x]);
		x += (float)PX_INDEX_CONV;
	}
}

void	put_out_background(t_img img, int px_start_y, int px_start_x)
{
	int	pix_y;
	int	pix_x;

	pix_y = px_start_y;
	while (++pix_y < px_start_y + MINI_PX)
	{
		pix_x = px_start_x - 1;
		while (++pix_x < px_start_x + MINI_PX)
			put_my_pixel(img, pix_y, pix_x, OUT_COLOR);
	}
}

void	magic_map_displayer(t_cub *cub, int	px_start_y, int px_start_x)
{
	float	y;
	float	x;
	int		pix_y;

	y = cub->player.y - MIDMINI;
	x = cub->player.x - MIDMINI;
	pix_y = px_start_y;
	put_out_background(cub->display, px_start_y, px_start_x);
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
	int		px_start_y;
	int		px_start_x;

	px_start_y = WIN_H - (MINI_PX + PIX_SPACE);
	px_start_x = PIX_SPACE;
	magic_map_displayer(cub, px_start_y, px_start_x);
}
