/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:30:59 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/29 12:28:29 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

// void	hitbox(float x ,float y, t_cub *cub)
// {
// 	cub->hit.x = x - 1 / 6.;
// 	cub->hit.y = y - 1 / 6.;
// 	cub->hit.cote = 1 / 3.;
// }

void	key_move(float valcos, float valsin, t_cub *cub)
{
	if (sin(valsin) < 0 && cub->map[(int)(cub->player.y - HITBOX)][(int)cub->player.x] != '1')
		cub->player.y += sin(valsin) * SPEED;
	else if (sin(valsin) > 0 && cub->map[(int)(cub->player.y + HITBOX)][(int)cub->player.x] != '1')
		cub->player.y += sin(valsin) * SPEED;
	if (cos(valcos) > 0 && cub->map[(int)cub->player.y][(int)(cub->player.x + HITBOX)] != '1')
		cub->player.x += cos(valcos) * SPEED;
	else if (cos(valcos) < 0 && cub->map[(int)cub->player.y][(int)(cub->player.x - HITBOX)] != '1')
		cub->player.x += cos(valcos) * SPEED;
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
	cub->player.angle -= (float)cub->key.right * ROTATE;
	cub->player.angle += (float)cub->key.left * ROTATE;
	if (cub->player.angle > 2 * PI)
		cub->player.angle -= 2 * PI;
	else if (cub->player.angle < 0)
		cub->player.angle += 2 * PI;
	cub->player.angle -= SENSI_MOUSE * (cub->mouse.x - WIN_W / 2);
}

void	key_manager(t_cub *cub)
{
	move_manager(cub);
	rotate_manager(cub);
}
