/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_missile_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:01:18 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 09:10:59 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	missile_init(t_en *en, t_cub *cub, float y, float x)
{
	en->miss.active = 1;
	en->miss.x = en->x;
	en->miss.y = en->y;
	en->miss.x_dest = x;
	en->miss.y_dest = y;
	en->miss.angle = get_angle(en->y - cub->player.y, en->x - cub->player.x);
}

void	throw_missile(t_en *en, t_cub *cub, float y, float x)
{
	en->time += cub->time;
	if (en->time / EN3_ATK_SPR_SPEED > 0)
	{
		if (en->sprite < en->nb_runspr)
			en->sprite = en->nb_runspr;
		if (en->sprite == en->nb_sprites)
		{
			en->time2 = 1;
			en->sprite = 0;
			en->action = E_ATTACK;
			en->time = 0;
		}
		else
		{
			en->img = cub->sprites[en->img_dir][en->sprite];
			en->sprite++;
			en->time = 0;
		}
		if (en->sprite == en->nb_sprites)
			missile_init(en, cub, y, x);
	}
}

void	throw_missile_manager(t_en *en, t_cub *cub, int dist)
{
	if (en->time2 / en->atk_speed < 1)
	{
		en->time2 += cub->time;
		if (dist > 3)
			enemy_move(en, cub);
		else
			en->img = cub->sprites[en->img_dir][0];
	}
	else if (en->miss.active == 0)
		throw_missile(en, cub, cub->player.y, cub->player.x);
	else if (dist >= 2)
		enemy_move(en, cub);
}
