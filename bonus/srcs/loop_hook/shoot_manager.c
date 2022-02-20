/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:46:26 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/20 12:51:18 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	check_if_hit(t_en *en, t_cub *cub, t_gun *gun)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	dist;
	float	m;
	float	x;

	delta_x = (cub->player.x - en->x);
	delta_y = (cub->player.y - en->y);
	dist = sqrtf(delta_x * delta_x + delta_y * delta_y);
	angle = atan(delta_y / delta_x * -1);
	if (angle < 0)
		angle += 2 * PI;
	if (delta_x < 0 && delta_y < 0)
		angle += PI;
	if (delta_x < 0 && delta_y > 0)
		angle -= PI;
	m = tan(angle - cub->player.angle + PI / 2);
	x = dist / m;
	delta_y = fabsf(delta_y);
	delta_x = fabsf(delta_x);
	if (delta_y > delta_x && ((sin(angle) > 0 && sin(cub->player.angle) > 0) || (sin(angle) < 0 && sin(cub->player.angle) < 0)))
		return ;
	else if (delta_x > delta_y && ((cos(angle) > 0 && cos(cub->player.angle) > 0) || (cos(angle) < 0 && cos(cub->player.angle) < 0)))
		return ;
	if (x < 0.3 && x > -0.3)
		en->life -= gun->damage;
}

void	hit_manager(t_cub *cub, t_gun *gun)
{
	t_ray	r;
	int		i;

	i = -1;
	(void)gun;
	r.p_angle = cub->player.angle;
	while (cub->en[++i].action != -1)
		check_if_hit(&cub->en[i], cub, gun);
}

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
		hit_manager(cub, gun);
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
