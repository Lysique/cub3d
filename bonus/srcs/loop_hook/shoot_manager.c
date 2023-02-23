/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:46:26 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/22 14:10:50 by tamighi          ###   ########.fr       */
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
		gun->status = GS_SHOT;
	if (gun->status == GS_SHOT && gun->time / MACHINGUN_SPEED > 0)
	{
		if (gun->sprite == 0)
			gun->sprite = 1;
		else
			gun->sprite += gun->sprite % 2 * 2 - 1;
		gun->time -= MACHINGUN_SPEED;
		hit_manager(cub, gun);
	}
}

void	shotgun_shot(t_cub *cub, t_gun *gun)
{
	gun->time += cub->time;
	if (gun->status == GS_FREE)
	{
		gun->status = GS_SHOT;
		gun->sprite = 1;
		hit_manager(cub, gun);
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
