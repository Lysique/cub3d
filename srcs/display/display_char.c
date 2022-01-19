/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:53:31 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/10 14:27:47 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	ft_draw_0(float ax, float ay, float by, t_img img)
{
	if (by > 140)
		while (ay <= 160)
			put_my_pixel(img, ax, ay++, 0xFF0000);
	else if (by < 140)
		while (ay >= 120)
			put_my_pixel(img, ax, ay--, 0xFF0000);
}

float	ft_dist(float ax, float ay, float bx, float by)
{
	const float	dy = by - ay;
	const float	dx = bx - ax;

	return (sqrtf(dy * dy + dx * dx));
}

void	ft_draw_line(t_img img, t_cub *cub)
{
	float	ax;
	float	ay;
	float	bx;
	float	by;
	float	d;

	ax = 140;
	ay = 140;
	bx = cos(cub->player.angle) * 20 + ax;
	by = sin(cub->player.angle) * 20 + ay;
	d = 0;
	cub->line.pente = (by - ay) / (bx - ax);
	if (bx > 139 && bx < 141)
		ft_draw_0(ax, ay, by, img);
	else
	{
		while (ft_dist(ax, ay, ax + d, ax + d * cub->line.pente) <= 20)
		{
			put_my_pixel(img, ax + d, ay + d * cub->line.pente, 0xFF0000);
			if (ax > bx)
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

	pix_y = 135;
	while (pix_y < 145)
	{
		pix_x = 135;
		while (pix_x < 145)
		{
			put_my_pixel(img, pix_x++, pix_y, 0x000000FF);
		}
		pix_y++;
	}
	ft_draw_line(img, cub);
}
