/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:44:20 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 13:22:35 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	bite_player(t_en *en, t_cub *cub)
{
	en->time += cub->time;
	en->sprite = en->time / 200;
	if (en->sprite < 3)
		en->img = cub->sprites[EN1_ATK][en->sprite];
	if (en->sprite == 2 && en->action != E_HAS_ATK && cub->player.life > 0)
	{
		en->action = E_HAS_ATK;
		cub->player.life -= 1;
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
}
