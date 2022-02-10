/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:53:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/10 11:18:08 by tamighi          ###   ########.fr       */
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
	while (sqrtf(((d * pente) * (d * pente)) + d * d) <= CHAR_LINE_SIZE)
	{
		put_my_pixel(img, (WIN_H - MINI_PX_Y / 2 - d * pente) - MINI_PX_SPACE_Y,
			(MINI_PX_X / 2 + d) + MINI_PX_SPACE_X, CHAR_LINE_COLOR);
		if (bx < 0)
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
	pix_y = (WIN_H - MINI_PX_Y / 2 - CHAR_SIZE / 2) - MINI_PX_SPACE_Y;
	while (pix_y < (WIN_H - MINI_PX_Y / 2 + CHAR_SIZE / 2) - MINI_PX_SPACE_Y)
	{
		pix_x = (MINI_PX_X / 2 - CHAR_SIZE / 2) + MINI_PX_SPACE_X;
		while (pix_x < (MINI_PX_X / 2 + CHAR_SIZE / 2) + MINI_PX_SPACE_X)
			put_my_pixel(img, pix_y, pix_x++, CHAR_COLOR);
		pix_y++;
	}
	ft_draw_line(img, cub);
}
