/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:16:09 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 13:17:02 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	en1_die(t_en *en, t_cub *cub)
{
	if (en->time > EN1_DYING_SPR_SPEED)
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

void	enemy_die(t_en *en, t_cub *cub)
{
	if (en->type == NAKED_EN)
		en1_die(en, cub);
}
