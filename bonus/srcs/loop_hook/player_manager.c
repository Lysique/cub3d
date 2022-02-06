/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:30:59 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/06 11:26:19 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	music_manager(t_cub *cub)
{
	static int	i = 0;
	static int	j = 0;

	if (cub->key.w == 1 || cub->key.s == 1
		|| cub->key.a == 1 || cub->key.d == 1)
	{
		if (!(i % 5) && j % 2)
			system("afplay -v 0.5 -t 2 music/bruit_pas1.mp3 &>/dev/null &");
		else if (!(i % 5) && !(j % 2))
			system("afplay -v 0.5 -t 2 bonus/sounds/step2.mp3 &>/dev/null &");
		i++;
		j++;
	}
}

void	key_move(float valcos, float valsin, t_cub *cub)
{
	float			y;
	float			x;

	y = cub->player.y;
	x = cub->player.x;
	if (sin(valsin) < 0 && cub->map[(int)(y - HITBOX)][(int)x] != '1')
		cub->player.y += sin(valsin) * SPEED * cub->time;
	else if (sin(valsin) > 0 && cub->map[(int)(y + HITBOX)][(int)x] != '1')
		cub->player.y += sin(valsin) * SPEED * cub->time;
	if (cos(valcos) > 0 && cub->map[(int)y][(int)(x + HITBOX)] != '1')
		cub->player.x += cos(valcos) * SPEED * cub->time;
	else if (cos(valcos) < 0 && cub->map[(int)y][(int)(x - HITBOX)] != '1')
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
	cub->player.angle -= (float)cub->key.right * ROTATE * cub->time;
	cub->player.angle += (float)cub->key.left * ROTATE * cub->time;
	if (cub->player.angle > 2 * PI)
		cub->player.angle -= 2 * PI;
	else if (cub->player.angle < 0)
		cub->player.angle += 2 * PI;
	cub->player.angle -= SENSI_MOUSE * (cub->mouse.x - WIN_W / 2);
}

void	player_manager(t_cub *cub)
{
	static t_time	time = 0;

	if (time == 0)
		time = get_time();
	cub->time = get_time() - time;
	move_manager(cub);
	rotate_manager(cub);
	music_manager(cub);
	time = get_time();
}
