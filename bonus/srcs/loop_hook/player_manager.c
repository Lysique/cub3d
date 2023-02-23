/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:30:59 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/07 12:57:12 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	key_move(float valcos, float valsin, t_cub *cub)
{
	float			y;
	float			x;

	y = cub->player.y;
	x = cub->player.x;
	if (sin(valsin) < 0 && check_p_dir(cub, y - HITBOX, x))
		cub->player.y += sin(valsin) * SPEED * cub->time;
	else if (sin(valsin) > 0 && check_p_dir(cub, y + HITBOX, x))
		cub->player.y += sin(valsin) * SPEED * cub->time;
	if (cos(valcos) > 0 && check_p_dir(cub, y, x + HITBOX))
		cub->player.x += cos(valcos) * SPEED * cub->time;
	else if (cos(valcos) < 0 && check_p_dir(cub, y, x - HITBOX))
		cub->player.x += cos(valcos) * SPEED * cub->time;
}

void	move_manager(t_cub *cub)
{
	if (cub->key.w == 1)
		key_move(cub->player.angle, cub->player.angle * -1, cub);
	if (cub->key.s == 1)
		key_move(cub->player.angle + PI, cub->player.angle, cub);
	if (cub->key.a == 1)
		key_move(cub->player.angle + MIDPI, cub->player.angle - MIDPI, cub);
	if (cub->key.d == 1)
		key_move(cub->player.angle - MIDPI, cub->player.angle + MIDPI, cub);
}

void	rotate_manager(t_cub *cub)
{
	if (cub->key.right)
		cub->player.angle -= ROTATE * cub->time;
	if (cub->key.left)
		cub->player.angle += ROTATE * cub->time;
	if (cub->player.angle > 2 * PI)
		cub->player.angle -= 2 * PI;
	else if (cub->player.angle < 0)
		cub->player.angle += 2 * PI;
	cub->player.angle -= SENSI_MOUSE * cub->time * (cub->mouse.x - WIN_W / 2);
	cub->mouse.x = WIN_W / 2;
}

void	player_manager(t_cub *cub)
{
	move_manager(cub);
	rotate_manager(cub);
	if (cub->map_dist[(int)cub->player.y][(int)cub->player.x] != 0)
		map_dist_manager(cub);
}
