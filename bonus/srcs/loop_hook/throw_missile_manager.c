/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_missile_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:01:18 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 17:40:44 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	missile_init(t_en *en, t_cub *cub)
{
//	en->miss.active = 1;
	en->miss.x = en->x;
	en->miss.y = en->y;
	en->miss.x_dest = cub->player.x;
	en->miss.y_dest = cub->player.y;
	en->miss.angle = get_angle(en->y - cub->player.y, en->x - cub->player.x);
}

void	throw_missile(t_en *en, t_cub *cub)
{
	if (en->time2 / EN3_ATK_SPR_SPEED > 0)
	{
		if (en->sprite < en->nb_runspr)
			en->sprite = en->nb_runspr;
		if (en->sprite == en->nb_sprites)
		{
			en->sprite = 0;
			en->action = E_RECHARGE;
		}
		else
		{
			en->img = cub->sprites[en->img_dir][en->sprite];
			en->sprite++;
			en->time2 = 0;
		}
	}
	if (en->sprite == en->nb_sprites && !en->miss.active)
		missile_init(en, cub);
}

void	throw_missile_manager(t_en *en, t_cub *cub, int dist)
{
	en->time2 += cub->time;
	if (en->action == E_RECHARGE)
	{
		if (dist >= 2)
			enemy_move(en, cub);
		if (en->time2 / en->atk_speed > 0)
		{
			en->time2 = 0;
			en->action = E_ATTACK;
		}
	}
	else if (en->miss.active == 0)
		throw_missile(en, cub);
	else if (dist >= 2)
		enemy_move(en, cub);
}
