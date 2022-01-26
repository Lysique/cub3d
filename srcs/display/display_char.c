/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:53:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/26 08:10:42 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	ft_draw_0(float by, t_img img)
{
	int	ay;

	ay = MINI_PX / 2;
	if (by < MINI_PX / 2)
		while (ay <= MINI_PX / 2 + 20)
			put_my_pixel(img, MINI_PX / 2, ay++, RED);
	else if (by > MINI_PX / 2)
		while (ay >= MINI_PX / 2 - 20)
			put_my_pixel(img, MINI_PX / 2, ay--, RED);
}

float	ft_dist(float bx, float by)
{
	const float	dy = by - MINI_PX / 2;
	const float	dx = bx - MINI_PX / 2;

	return (sqrtf(dy * dy + dx * dx));
}

void	ft_draw_line(t_img img, t_cub *cub)
{
	float	bx;
	float	by;
	float	d;
	float	pente;

	bx = cos(cub->player.angle) * 20 + MINI_PX / 2;
	by = sin(cub->player.angle) * 20 + MINI_PX / 2;
	d = 0;
	pente = (by - MINI_PX / 2) / (bx - MINI_PX / 2);
	if (bx < MINI_PX / 2 + 1 && bx > MINI_PX / 2 - 1)
		ft_draw_0(by, img);
	else
	{
		while (ft_dist(MINI_PX / 2  - d, MINI_PX / 2 - d * pente) <= 20)
		{
			put_my_pixel(img, MINI_PX / 2 - d, MINI_PX / 2 - d * pente, RED);
			if (MINI_PX / 2 > bx)
				d -= .1;
			else
				d += .1;
		}
	}
}

void	display_char(t_cub *cub, t_img img)
{
	int	pix_x;
	int	pix_y;

	pix_y = MINI_PX / 2 - 5;
	while (pix_y < MINI_PX / 2 + 5)
	{
		pix_x = MINI_PX / 2 - 5;
		while (pix_x < MINI_PX / 2 + 5)
			put_my_pixel(img, pix_x++, pix_y, BLUE);
		pix_y++;
	}
	(void)cub;
	ft_draw_line(img, cub);
}
