/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_boss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:58:33 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 17:42:16 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	boss_action_manager(t_en *en, t_cub *cub, int dist)
{
	if (en->action == E_ATTACK || en->action == E_RECHARGE)
		throw_missile_manager(en, cub, dist);
	else if (dist == INT_MAX && en->action == E_AGGRO)
		boss_destroy_door(en, cub);
	else if (en->action == E_CHASE)
		enemy_move(en, cub);
}

void	set_boss_action(t_en *en, t_cub *cub, int dist)
{
	if (en_shot_manager(en, cub) && dist < en->atk_range && en->action != E_RECHARGE)
		en_action_reset(en, E_ATTACK);
	else if (dist < en->aggro_range)
		en_action_reset(en, E_CHASE);
}

void	manage_boss(t_en *en, t_cub *cub)
{
	if (en->life <= 0)
		return ;
	set_en_img_angle(en, cub);
	set_boss_action(en, cub, cub->map_dist[(int)en->y][(int)en->x]);
	boss_action_manager(en, cub, cub->map_dist[(int)en->y][(int)en->x]);
	(void)en;
	(void)cub;
}
