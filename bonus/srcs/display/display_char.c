/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:53:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/10 08:12:40 by tamighi          ###   ########.fr       */
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
		put_my_pixel(img, WIN_H - MINI_PX / 2 - d
			* pente + PIX_SPACE, MINI_PX / 2 + d, RED);
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
	pix_y = WIN_H - MINI_PX / 2 - 5 + PIX_SPACE;
	while (pix_y < WIN_H - MINI_PX / 2 + 5 + PIX_SPACE)
	{
		pix_x = MINI_PX / 2 - 5;
		while (pix_x < MINI_PX / 2 + 5)
			put_my_pixel(img, pix_y, pix_x++, BLUE);
		pix_y++;
	}
	ft_draw_line(img, cub);
}
