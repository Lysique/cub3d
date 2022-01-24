/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:30:59 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/24 09:10:18 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	move_manager(t_cub *cub)
{
	int		x;
	int		y;
	float	limit;

	x = cub->player.x;
	y = cub->player.y;
	limit = 0.35;
	if (cub->key.d && cub->map[(int)y][(int)(x + limit)] != '1'
		&& cub->map[(int)(y + limit - DISTANCE)][(int)(x + limit)] != '1'
		&& cub->map[(int)(y - limit + DISTANCE)][(int)(x + limit)] != '1')
		{
			// printf("d =%f %f\n", y + limit - DISTANCE, x + limit);
			// printf("d =%f %f\n", y - limit + DISTANCE, x + limit);
			cub->player.x += cub->key.d * DISTANCE;
		}
	if (cub->key.a && cub->map[(int)y][(int)(x - limit)] != '1'
		&& cub->map[(int)(y + limit - DISTANCE)][(int)(x - limit)] != '1'
		&& cub->map[(int)(y - limit + DISTANCE)][(int)(x - limit)] != '1')
		{
			// printf("a =%f %f\n", y + limit - DISTANCE, x - limit);
			// printf("a =%f %f\n", y - limit + DISTANCE, x - limit);
			cub->player.x -= cub->key.a * DISTANCE;
		}
	if (cub->key.s && cub->map[(int)(y + limit)][(int)x] != '1'
		&& cub->map[(int)(y + limit)][(int)(x + limit - DISTANCE)] != '1'
		&& cub->map[(int)(y + limit)][(int)(x - limit + DISTANCE)] != '1')
		{
			// printf("s =%f %f\n", y + limit, x + limit - DISTANCE);
			// printf("s =%f %f\n", y + limit, x - limit + DISTANCE);
			cub->player.y += cub->key.s * DISTANCE;
		}
	if (cub->key.w && cub->map[(int)(y - limit)][(int)x] != '1'
		&& cub->map[(int)(y - limit)][(int)(x + limit - DISTANCE)] != '1'
		&& cub->map[(int)(y - limit)][(int)(x - limit + DISTANCE)] != '1')
		{
			// printf("w =%f %f\n", y - limit, x + limit - DISTANCE);
			// printf("w =%f %f\n", y - limit, x - limit + DISTANCE);
			cub->player.y -= cub->key.w * DISTANCE;
		}
	// printf("ply =%f\n", cub->player.y);
	// printf("plx =%f\n", cub->player.x);
	display(cub);
}

void	rotate_manager(t_cub *cub)
{
	cub->player.angle += ROTATE * cub->key.right;
	cub->player.angle -= ROTATE * cub->key.left;
	if (cub->player.angle > 2 * PI)
		cub->player.angle = 0;
	else if (cub->player.angle < 0)
		cub->player.angle = 2 * PI;
}

void	key_manager(t_cub *cub)
{
	move_manager(cub);
	rotate_manager(cub);
}
