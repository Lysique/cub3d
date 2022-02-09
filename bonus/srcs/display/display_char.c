/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:53:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/09 09:41:06 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	ft_draw_0(float by, t_img img)
{
	int	ay;

	ay = WIN_H - MINI_PX / 2;
	if (by < 0)
		while (ay <= WIN_H - MINI_PX / 2 + 20)
			put_my_pixel(img, ay++, MINI_PX / 2, RED);
	else if (by > 0)
		while (ay >= WIN_H - MINI_PX / 2 - 20)
			put_my_pixel(img, ay--, MINI_PX / 2, RED);
}

float	ft_dist(float bx, float by)
{
	const float	dy = by;
	const float	dx = bx;

	return (sqrtf(dy * dy + dx * dx));
}

void	ft_draw_line(t_img img, t_cub *cub)
{
	float	bx;
	float	by;
	float	d;
	float	pente;

	bx = cos(cub->player.angle);
	by = sin(cub->player.angle);
	d = 0;
	pente = by / bx;
	if (bx < 0.05 && bx > -0.05)
		ft_draw_0(by, img);
	else
	{
		while (ft_dist(d, d * pente) <= 20)
		{
			put_my_pixel(img, WIN_H - MINI_PX / 2 - d
				* pente, MINI_PX / 2 + d, RED);
			if (0 > bx)
				d -= .1;
			else
				d += .1;
		}
	}
}

void	display_char(t_cub *cub)
{
	int		pix_x;
	int		pix_y;
	t_img	img;

	img = cub->display;
	pix_y = WIN_H - MINI_PX / 2 - 5;
	while (pix_y < WIN_H - MINI_PX / 2 + 5)
	{
		pix_x = MINI_PX / 2 - 5;
		while (pix_x < MINI_PX / 2 + 5)
			put_my_pixel(img, pix_y, pix_x++, BLUE);
		pix_y++;
	}
	ft_draw_line(img, cub);
}
