/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:28:43 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/12 11:13:27 by tamighi          ###   ########.fr       */
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
	if (gun->status == GS_FREE && (cub->key.shoot_r == 1 || gun->bullets == 0))
	{
		cub->key.shoot_p = 0;
		gun->time = 0;
	}
	else if (gun->status == GS_FREE)
	{
		gun->status = GS_SHOT;
		system("afplay -v 1 music/pompe_feu.mp3 &>/dev/null &");
		gun->sprite = 1;
		gun->bullets--;
	}
	if (gun->status == GS_SHOT && gun->time / SHOTGUN_SPEED > 0)
	{
		gun->status = GS_WAIT;
		gun->time -= SHOTGUN_SPEED;
		gun->sprite = 0;
	}
	else if (gun->status == GS_WAIT && gun->time / SHOTGUN_WAIT_TIME > 0)
	{
		gun->status = GS_FREE;
		cub->action = FREE_GUN;
		gun->time -= SHOTGUN_WAIT_TIME;
	}
}

void	swap_gun(t_cub *cub)
{
	system("afplay -v 0.2 music/change_arme.mp3 &>/dev/null &");
	if (cub->gun_type == 0)
		cub->gun_type = 1;
	else
		cub->gun_type = 0;
	cub->action = FREE_GUN;
	cub->key.swap_gun = 0;
}

void	reload_gun(t_cub *cub, t_gun *gun)
{
	gun->time += cub->time;
	if (gun->status == GS_FREE)
	{
		gun->sprite = gun->nb_spr_shoot + 1;
		gun->status = GS_RELOAD;
		if (cub->gun_type == 0)
			system("afplay -v 0.5 music/recharge_pompe.mp3 &>/dev/null &");
		else
			system("afplay -v 0.5 music/mitrailleuse_rech1.mp3 &>/dev/null &");
	}
	if (gun->time / RELOAD_GUN_SPEED > 0 && gun->status == GS_RELOAD)
	{
		if (cub->gun_type == 1 && gun->sprite == 4)
			system("afplay -v 0.5 music/mitrailleuse_rech2.mp3 &>/dev/null &");
		gun->time -= RELOAD_GUN_SPEED;
		gun->sprite += 1;
		if (gun->sprite == gun->nb_sprites)
		{
			gun->status = GS_FREE;
			gun->bullets = gun->max_bullets;
			gun->sprite = 0;
			gun->time = 0;
			cub->key.reload = 0;
			cub->key.shoot_p = 0;
			cub->key.swap_gun = 0;
			cub->action = FREE_GUN;
		}
	}
}

void	shot_gun(t_cub *cub, t_gun *gun)
{
	if (cub->gun_type == 0)
		shotgun_shot(cub, gun);
	else if (cub->gun_type == 1)
		machinegun_shot(cub, gun);
}

void	gun_action_checker(t_cub *cub, t_gun gun)
{
	if (cub->key.shoot_p == 1 && gun.bullets != 0)
		cub->action = SHOOTING;
	else if (cub->key.reload == 1)
		cub->action = RELOADING;
	else if (cub->key.swap_gun == 1)
		cub->action = SWAPPING_GUN;
}

void	gun_manager(t_cub *cub)
{
	if (cub->action == FREE_GUN)
		gun_action_checker(cub, cub->gun[cub->gun_type]);
	if (cub->action == SHOOTING)
		shot_gun(cub, &cub->gun[cub->gun_type]);
	else if (cub->action == RELOADING)
		reload_gun(cub, &cub->gun[cub->gun_type]);
	else if  (cub->action == SWAPPING_GUN)
		swap_gun(cub);
}
