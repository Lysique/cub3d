/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dying_boss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:27:16 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 16:40:20 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	dying_boss(t_en *en, t_cub *cub)
{
	en->time += cub->time;
	if (en->time / 50 > 0)
	{
		en->img = cub->sprites[I_MISS][en->sprite];
		en->div = 0.5;
		en->time = 0;
		en->sprite++;
		if (en->sprite == MISS_NB_SPRITES)
			en->action = E_DEAD;
	}
}
