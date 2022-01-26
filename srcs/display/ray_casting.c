/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:14:29 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/25 17:21:09 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

float	ft_dist2(float bx, float by)
{
	const float	dy = by;
	const float	dx = bx;

	return (sqrtf(dy * dy + dx * dx));
}

void	ray_casting2(t_cub *cub)
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

void	ray_casting(t_cub *cub)
{
	t_ray		r;
	t_player	p;

	p = cub->player;
	r.ray_r = p.angle;
	r.dir_x = cos(p.angle);
	r.dir_y = sin(p.angle);
	r.delta_x = fabsf(1 / r.dir_x);
	r.delta_y = fabsf(1 / r.dir_y);
	r.map_x = (int)p.x;
	r.map_y = (int)p.y;
	printf("Rad : %f, sin : %f, cos : %f\n", p.angle, r.dir_y, r.dir_x);
	if (r.dir_x < 0)
		r.side_x = (float)(p.x - r.map_x) * r.delta_x;
	else
		r.side_x = (float)(p.x + (float)1 - r.map_x) * r.delta_x;
	if (r.dir_y < 0)
		r.side_y = (float)(p.y - r.map_y) * r.delta_y;
	else
		r.side_y = (float)(p.y + (float)1 - r.map_y) * r.delta_y;
	printf("delta_x %f, delta_y %f, side_x %f, side_y %f\n", r.delta_x, r.delta_y, r.side_x, r.side_y);
	printf("X = %f, Y = %f, p.x %f, p.y %f\n", p.x + r.side_x, p.y + r.side_y, p.x, p.y);
}
