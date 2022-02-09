/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:28:43 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/09 13:31:41 by tamighi          ###   ########.fr       */
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
	if (cub->gun_type == 0)
		cub->gun_type = 1;
	else
		cub->gun_type = 0;
	cub->key.swap_gun = 0;
}

void	reload_gun(t_cub *cub)
{
	t_gun	*gun;

	gun = &cub->gun[gun_type];
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
