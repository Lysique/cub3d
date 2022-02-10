/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:28:43 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/10 13:26:39 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	machingun_shot(t_cub *cub, t_gun *gun)
{
	if (gun->bullets == 0)
		return ;
	gun->time += cub->time;
	if (gun->shooting == 0)
	{
		gun->shooting = 1;
		gun->sprite += 1;
	}
	else if (gun->time / 70 > 1 && gun->sprite == 1)
		gun->sprite = 2;
	else if (gun->time / 70 > 1 && gun->sprite == 2)
		gun->sprite = 1;
	if (gun->time / 70 > 1)
	{
		gun->time -= 70;
		gun->bullets--;
		system("afplay -v 1 -t 1 music/mitrailleuse_tir.mp3 &>/dev/null &");
	}
	if (cub->key.shoot_r == 1 || gun->bullets == 0)
	{
		cub->key.shoot_r = 0;
		cub->key.shoot_p = 0;
		gun->shooting = 0;
		gun->sprite = 0;
	}
}

void	shotgun_shot(t_cub *cub, t_gun *gun)
{
	if (gun->bullets == 0)
		return ;
	gun->time += cub->time;
	if (gun->shooting == 0)
	{
		gun->shooting = 1;
		gun->sprite += 1;
		system("afplay -v 1 music/pompe_feu.mp3 &>/dev/null &");
	}
	else if (gun->time / 100 > 1 && gun->sprite != 0)
		gun->sprite -= 1;
	else if (gun->time / 500 > 1)
	{
		gun->shooting = 0;
		gun->time = 0;
		gun->bullets--;
		if (cub->key.shoot_r == 1)
		{
			cub->key.shoot_r = 0;
			cub->key.shoot_p = 0;
		}	
	}
}

void	swap_gun(t_cub *cub)
{
	t_gun	*gun;

	gun = &cub->gun[cub->gun_type];
	gun->sprite = 0;
	gun->time = 0;
	gun->shooting = 0;
	system("afplay -v 0.2 music/change_arme.mp3 &>/dev/null &");
	if (cub->gun_type == 0)
		cub->gun_type = 1;
	else
		cub->gun_type = 0;
	cub->key.swap_gun = 0;
}

void	reload_gun(t_cub *cub)
{
	t_gun	*gun;

	gun = &cub->gun[cub->gun_type];
	gun->time += cub->time;
	if (gun->reloading == 0)
	{
		gun->sprite = gun->nb_spr_shoot + 1;
		gun->reloading = 1;
		if (cub->gun_type == 0)
			system("afplay -v 0.5 music/recharge_pompe.mp3 &>/dev/null &");
		else
			system("afplay -v 0.5 music/mitrailleuse_rech1.mp3 &>/dev/null &");
	}
	else if (gun->time / 150 > 1)
	{
		gun->time -= 100;
		gun->sprite += gun->reloading;
		if (cub->gun_type == 1 && gun->sprite == 4)
				system("afplay -v 0.5 music/mitrailleuse_rech2.mp3 &>/dev/null &");
		if (gun->sprite == gun->nb_sprites)
		{
			if (cub->gun_type == 0)
				gun->bullets = 2;
			else
				gun->bullets = 50;
			gun->reloading = 0;
			cub->key.reload = 0;
			gun->sprite = 0;
			cub->key.shoot_p = 0;
			cub->key.swap_gun = 0;
		}
	}
}

void	gun_manager(t_cub *cub)
{
	static t_time	time = 0;

	if (time == 0)
		time = get_time();
	cub->time = get_time() - time;
	time = get_time();
	if (cub->key.reload == 1)
		reload_gun(cub);
	else if (cub->key.swap_gun == 1)
		swap_gun(cub);
	else if (cub->key.shoot_p == 1 || cub->gun[cub->gun_type].shooting == 1)
	{
		if (cub->gun_type == 0)
			shotgun_shot(cub, &cub->gun[0]);
		else if (cub->gun_type == 1)
			machingun_shot(cub, &cub->gun[1]);
	}
}
