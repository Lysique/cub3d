/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:44:20 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/07 12:24:29 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

int	en_shot_manager(t_en *en, t_cub *cub, float en_angle)
{
	float	d_x;
	float	d_y;
	float	angle;
	float	dist;
	float	m;

	d_x = en->x - cub->player.x;
	d_y = en->y - cub->player.y;
	dist = sqrtf(d_x * d_x + d_y * d_y);
	angle = get_angle(d_y, d_x);
	if (bad_trajectory_checker(angle, d_x, d_y, en_angle) == 1)
		return (0);
	if (lh_wall_hit_checker(en_angle, dist, en->x, en->y) == 1)
		return (0);
	m = tan(angle - en_angle + PI / 2);
	if (dist / m < HITBOX && dist / m > -HITBOX)
		return (1);
	return (0);
}

int	check_shot_walls(t_en *en, t_cub *cub, float angle)
{
	float	x;
	float	y;
	float	dist;
	float	d_x;
	float	d_y;

	d_x = en->x - cub->player.x;
	d_y = en->y - cub->player.y;
	dist = sqrtf(d_x * d_x + d_y * d_y);
	x = en->x + (cos(angle) * 0.2);
	y = en->y - (sin(angle) * 0.2);
	if (lh_wall_hit_checker(angle, dist, x, y))
		return (0);
	x = en->x - (cos(angle) * 0.2);
	y = en->y + (sin(angle) * 0.2);
	if (lh_wall_hit_checker(angle, dist, x, y))
		return (0);
	return (1);
}

void	shoot_player(t_en *en, t_cub *cub)
{
	en->time += cub->time;
	if (en->action == E_ATTACK)
	{
		en->angle = get_angle(en->y - cub->player.y, en->x - cub->player.x);
		if (en_shot_manager(en, cub, en->angle) == 0
			|| check_shot_walls(en, cub, en->angle) == 0)
		{
			enemy_move(en, cub);
			return ;
		}
		en->action = E_HAS_ATK;
	}
	if (en->time / EN2_ATK_SPEED <= 0)
		en->sprite = 0;
	else
	{
		system("afplay -v 1 -t 1 music/mitrailleuse_tir.mp3 &>/dev/null &");
		if (en_shot_manager(en, cub, en->angle))
			player_life_manager(cub, 1);
		en->sprite = 1;
		en->time = 0;
		en->action = E_STILL;
	}
	en->img = cub->sprites[EN2_ATK][en->sprite];
}

void	bite_player(t_en *en, t_cub *cub)
{
	en->time += cub->time;
	en->sprite = en->time / 200;
	if (en->sprite < 3)
		en->img = cub->sprites[EN1_ATK][en->sprite];
	if (en->sprite == 2 && en->action != E_HAS_ATK && cub->player.life > 0)
	{
		system("afplay -v 1 -t 1 music/ennemi_mord.mp3 &>/dev/null &");
		en->action = E_HAS_ATK;
		player_life_manager(cub, 1);
	}
	if (en->time / 1500 > 0)
	{
		en->sprite = 0;
		en->time = 0;
		en->action = E_STILL;
	}
}

void	enemy_attack(t_en *en, t_cub *cub)
{
	if (en->type == NAKED_EN)
		bite_player(en, cub);
	else if (en->type == SOLDIER_EN)
		shoot_player(en, cub);
}
