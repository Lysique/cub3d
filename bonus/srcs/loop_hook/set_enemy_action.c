/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemy_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:33:20 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 13:55:54 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	en_action_reset(t_en *en, int action)
{
	if (en->action != action)
	{
		en->action = action;
		en->time = 0;
		en->sprite = 0;
	}
}

void	set_enemy_action(t_en *en, t_cub *cub)
{
	float	d_x;
	float	d_y;
	float	dist;

	d_x = en->x - cub->player.x;
	d_y = en->y - cub->player.y;
	dist = sqrtf(d_x * d_x + d_y * d_y);
	if (en->life <= 0)
		en_action_reset(en, E_DIE);
	else if (cub->player.life <= 0)
		en_action_reset(en, E_STILL);
	else if (en->action == E_HAS_ATK)
		en_action_reset(en, E_HAS_ATK);
	else if (en->action == E_ATTACK || dist <= en->atk_range)
		en_action_reset(en, E_ATTACK);
	else if (en->life < en->max_life
		&& cub->map_dist[(int)en->y][(int)en->x] != INT_MAX)
		en_action_reset(en, E_CHASE);
	else if (cub->map_dist[(int)en->y][(int)en->x] <= en->aggro_range)
		en_action_reset(en, E_CHASE);
	else
		en_action_reset(en, E_STILL);
}
