/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_missile_manager.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:01:18 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 14:32:23 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	missile_init(t_en *en)
{
	en->miss.active = 1;
	en->miss.x = en->x;
	en->miss.y = en->y;
	en->miss.dist = sqrtf((en->miss.x - en->miss.x_dest)
			* (en->miss.x - en->miss.x_dest)
			+ (en->miss.y - en->miss.y_dest) * (en->miss.y - en->miss.y_dest));
	en->miss.angle = get_angle(en->miss.y - en->miss.y_dest,
			en->miss.x - en->miss.x_dest);
}

void	throw_missile_manager(t_en *en, t_cub *cub)
{
	en->time += cub->time;
	if (en->time / EN3_ATK_SPR_SPEED > 0)
	{
		if (en->sprite < en->nb_runspr)
			en->sprite = en->nb_runspr;
		if (en->sprite == en->nb_sprites)
		{
			en->time2 = 0;
			en->sprite = 0;
			en->img = cub->sprites[en->img_dir][en->sprite];
			en->action = E_HAS_ATK;
			en->time = 0;
		}
		else
		{
			en->img = cub->sprites[en->img_dir][en->sprite];
			en->sprite++;
			en->time = 0;
		}
		if (en->sprite == en->nb_sprites)
			missile_init(en);
	}
}
