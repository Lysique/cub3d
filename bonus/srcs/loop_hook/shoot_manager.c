/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:46:26 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/14 09:30:52 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	machinegun_shot(t_cub *cub, t_gun *gun)
{
	gun->time += cub->time;
	if (cub->key.shoot_r == 1 || gun->bullets == 0)
	{
		cub->key.shoot_p = 0;
		cub->action = FREE_GUN;
		gun->time = 0;
		gun->sprite = 0;
		gun->status = GS_FREE;
	}
	else if (gun->status == GS_FREE)
	{
		gun->status = GS_SHOT;
		gun->bullets--;
		system("afplay -v 1 -t 1 music/mitrailleuse_tir.mp3 &>/dev/null &");
		gun->sprite = 1;
	}
	if (gun->status == GS_SHOT && gun->time / MACHINGUN_SPEED > 0)
	{
		gun->sprite += gun->sprite % 2 * 2 - 1;
		gun->time -= MACHINGUN_SPEED;
		gun->bullets--;
		system("afplay -v 1 -t 1 music/mitrailleuse_tir.mp3 &>/dev/null &");
	}
}

void	shotgun_shot(t_cub *cub, t_gun *gun)
{
	gun->time += cub->time;
	if (gun->status == GS_FREE)
	{
		gun->status = GS_SHOT;
		system("afplay -v 1 music/pompe_feu.mp3 &>/dev/null &");
		gun->sprite = 1;
		gun->bullets--;
	}
	else if (gun->status == GS_SHOT && gun->time / SHOTGUN_SPEED > 0)
	{
		gun->status = GS_WAIT;
		gun->time -= SHOTGUN_SPEED;
		gun->sprite = 0;
	}
	else if (gun->status == GS_WAIT && gun->time / SHOTGUN_WAIT_TIME > 0)
	{
		gun->status = GS_FREE;
		cub->action = FREE_GUN;
		cub->key.shoot_p = 0;
		gun->time = 0;
		if (cub->key.shoot_r == 1)
			cub->key.shoot_p = 0;
	}
}

void	shoot_manager(t_cub *cub, t_gun *gun)
{
	if (cub->gun_type == 0)
		shotgun_shot(cub, gun);
	else if (cub->gun_type == 1)
		machinegun_shot(cub, gun);
}
