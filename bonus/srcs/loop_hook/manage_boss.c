/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_boss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:58:33 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 11:39:09 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	lock_boss_angle(t_en *en, t_cub *cub, int dist)
{
	if (dist == INT_MAX)
	{
		if (boss_found_door(en, cub))
			en->action = E_ATTACK;
		else
			en->action = E_STILL;
	}
	else
	{
		en->miss.x_dest = cub->player.x;
		en->miss.y_dest = cub->player.y;
		en->action = E_ATTACK;
		en->angle = get_angle(en->y - cub->player.y, en->x - cub->player.x);
	}
}

void	boss_action_manager(t_en *en, t_cub *cub, int dist)
{
	if (en->action == E_LOCK && en->miss.active == 0)
		lock_boss_angle(en, cub, dist);
	if (en->action == E_ATTACK)
		throw_missile_manager(en, cub);
	else if (en->action == E_CHASE)
		enemy_move(en, cub);
	if (en->miss.active != 0)
		missile_manager(en, cub);
}

void	set_boss_action(t_en *en, t_cub *cub, int dist)
{
	float	angle;

	angle = get_angle(en->y - cub->player.y, en->x - cub->player.x);
	if (en->time2 / en->atk_speed < 1)
	{
		en->time2 += cub->time;
		if (dist == INT_MAX && en->action != E_STILL)
			en_action_reset(en, E_LOCK);
		else if (dist > 3 && en->action != E_STILL)
			enemy_move(en, cub);
		else
			en->img = cub->sprites[en->img_dir][0];
	}
	else if (en->action == E_ATTACK)
		en_action_reset(en, E_ATTACK);
	else if (en_shot_manager(en, cub, angle) && dist < en->atk_range)
		en_action_reset(en, E_LOCK);
	else if (dist < en->aggro_range)
		en_action_reset(en, E_CHASE);
}

void	manage_boss(t_en *en, t_cub *cub)
{
	if (en->life <= 0)
		return ;
	set_boss_action(en, cub, cub->map_dist[(int)en->y][(int)en->x]);
	boss_action_manager(en, cub, cub->map_dist[(int)en->y][(int)en->x]);
}
