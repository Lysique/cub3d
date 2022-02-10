/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:28:43 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/10 17:13:18 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	machingun_shot(t_cub *cub, t_gun *gun)
{
	gun->time += cub->time;
	if (gun->action == FREE_GUN)
	{
		gun->action = SHOOTING;
		gun->sprite = 1;
	}
	if (gun->time / MACHINGUN_SPEED > 0)
	{
		gun->sprite += gun->sprite % 2 * 2 - 1;
		gun->time -= MACHINGUN_SPEED;
		gun->bullets--;
	}
	if (cub->key.shoot_r == 1 || gun->bullets == 0)
	{
		cub->key.shoot_r = 0;
		cub->key.shoot_p = 0;
		gun->action = FREE_GUN;
		gun->time = 0;
		gun->sprite = 0;
	}
}

void	shotgun_shot(t_cub *cub, t_gun *gun)
{
	gun->time += cub->time;
	if (gun->action == FREE_GUN)
	{
		gun->action = SHOOTING;
		gun->sprite = 1;
		gun->bullets--;
	}
	else if (gun->time / SHOTGUN_SPEED > 0 && gun->sprite == 1)
		gun->sprite -= 1;
	else if (gun->time / (SHOTGUN_WAIT_TIME + SHOTGUN_SPEED) > 0)
	{
		gun->action = FREE_GUN;
		gun->time = 0;
		if (cub->key.shoot_r == 1)
		{
			cub->key.shoot_r = 0;
			cub->key.shoot_p = 0;
		}	
	}
}

void	swap_gun(t_cub *cub, t_gun *gun)
{
	gun->time += cub->time;
	if (gun->action == FREE_GUN)
	{
		if (cub->gun_type == 0)
			cub->gun_type = 1;
		else
			cub->gun_type = 0;
		cub->gun[cub->gun_type].action = SWAPPING_GUN;
	}
	else if (gun->time / SWAP_GUN_BREAK > 0)
	{
		gun->action = FREE_GUN;
		gun->time = 0;
		cub->key.swap_gun = 0;
	}
}

void	reload_gun(t_cub *cub, t_gun *gun)
{
	gun->time += cub->time;
	if (gun->action == FREE_GUN)
	{
		gun->action = RELOADING;
		gun->sprite = gun->nb_spr_shoot + 1;
	}
	if (gun->time / RELOAD_GUN_SPEED > 0)
	{
		gun->time -= RELOAD_GUN_SPEED;
		gun->sprite += 1;
		if (gun->sprite == gun->nb_sprites)
		{
			gun->action = FREE_GUN;
			gun->bullets = gun->max_bullets;
			gun->sprite = 0;
			gun->time = 0;
			cub->key.reload = 0;
			cub->key.shoot_p = 0;
			cub->key.swap_gun = 0;
		}
	}
}

int	gun_action_checker(t_gun gun, int action, int key)
{
	if (action == SHOOTING && gun.action == FREE_GUN && gun.bullets == 0)
		return (0);
	if (key && (gun.action == FREE_GUN || gun.action == action))
		return (1);
	return (0);
}

void	gun_manager(t_cub *cub)
{
	if (gun_action_checker(cub->gun[cub->gun_type], RELOADING,
			cub->key.reload) == 1)
		reload_gun(cub, &cub->gun[cub->gun_type]);
	else if (gun_action_checker(cub->gun[cub->gun_type], SWAPPING_GUN,
			cub->key.swap_gun) == 1)
		swap_gun(cub, &cub->gun[cub->gun_type]);
	else if (gun_action_checker(cub->gun[cub->gun_type], SHOOTING,
			cub->key.shoot_p) == 1)
	{
		if (cub->gun_type == 0)
			shotgun_shot(cub, &cub->gun[0]);
		else if (cub->gun_type == 1)
			machingun_shot(cub, &cub->gun[1]);
	}
}
