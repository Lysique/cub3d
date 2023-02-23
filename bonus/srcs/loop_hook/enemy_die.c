/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:16:09 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/07 12:18:11 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	naked_die(t_en *en, t_cub *cub)
{
	if (en->time / EN1_DYING_SPR_SPEED > 0)
	{
		en->img = cub->sprites[EN1_DEAD][en->sprite];
		if (en->sprite == 3)
			en->offset += 100;
		else if (en->sprite == 4)
			en->offset += 100;
		else if (en->sprite == 5)
			en->offset += 100;
		en->sprite++;
		if (en->sprite == 9)
			en->action = E_DEAD;
		en->time = 0;
	}
	en->time += cub->time;
}

void	soldier_die(t_en *en, t_cub *cub)
{
	if (en->time / EN2_DYING_SPR_SPEED > 0)
	{
		en->img = cub->sprites[EN2_DEAD][en->sprite];
		en->sprite++;
		if (en->sprite == 7)
			en->action = E_DEAD;
		en->time = 0;
	}
	en->time += cub->time;
}

void	enemy_die(t_en *en, t_cub *cub)
{
	if (en->type == NAKED_EN)
		naked_die(en, cub);
	else if (en->type == SOLDIER_EN)
		soldier_die(en, cub);
}
