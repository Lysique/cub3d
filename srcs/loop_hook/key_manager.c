/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:30:59 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 15:03:31 by tamighi          ###   ########.fr       */
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
	cub->player.view += ROTATE * cub->key.right;
	cub->player.view -= ROTATE * cub->key.left;
	if (cub->player.view >= 360)
		cub->player.view = 0;
	else if (cub->player.view < 0)
		cub->player.view = 360 - ROTATE;
}

void	key_manager(t_cub *cub)
{
	move_manager(cub);
	rotate_manager(cub);
}
