/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:30:59 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 16:28:46 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	move_manager(t_cub *cub)
{
	int	x;
	int	y;
	int	limit;

	x = cub->player.x;
	y = cub->player.y;
	limit = UNIT / 3;
	if (cub->map[y / UNIT][(x + limit) / UNIT] != '1'
		&& cub->map[(y + limit - DISTANCE) / UNIT][(x + limit) / UNIT] != '1'
		&& cub->map[(y - limit + DISTANCE) / UNIT][(x + limit) / UNIT] != '1')
		cub->player.x += cub->key.d * DISTANCE;
	if (cub->map[y / UNIT][(x - limit) / UNIT] != '1'
		&& cub->map[(y + limit - DISTANCE) / UNIT][(x - limit) / UNIT] != '1'
		&& cub->map[(y - limit + DISTANCE) / UNIT][(x - limit) / UNIT] != '1')
		cub->player.x -= cub->key.a * DISTANCE;
	if (cub->map[(y + limit) / UNIT][x / UNIT] != '1'
		&& cub->map[(y + limit) / UNIT][(x + limit - DISTANCE) / UNIT] != '1'
		&& cub->map[(y + limit) / UNIT][(x - limit + DISTANCE) / UNIT] != '1')
		cub->player.y += cub->key.s * DISTANCE;
	if (cub->map[(y - limit) / UNIT][x / UNIT] != '1'
		&& cub->map[(y - limit) / UNIT][(x + limit - DISTANCE) / UNIT] != '1'
		&& cub->map[(y - limit) / UNIT][(x - limit + DISTANCE) / UNIT] != '1')
		cub->player.y -= cub->key.w * DISTANCE;
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
