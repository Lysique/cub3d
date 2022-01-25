/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:14:29 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/25 12:41:38 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

float	ft_dist2(float bx, float by)
{
	const float	dy = by;
	const float	dx = bx;

	return (sqrtf(dy * dy + dx * dx));
}

void	ray_casting(t_cub *cub)
{
	float	bx;
	float	by;
	float	d;
	float	pente;

	bx = cos(cub->player.angle);
	by = sin(cub->player.angle);
	d = 0;
	pente = by / bx;
	if (bx < 0.05 && bx > 0.05 * -1)
		return ;
	while (ft_dist2(d, d * pente) <= 20)
	{
		put_my_pixel(cub->display, MINI_PX / 2 + d, MINI_PX / 2 + d * pente, RED);
		if (bx > 0)
			d -= .1;
		else
			d += .1;
	}
}
