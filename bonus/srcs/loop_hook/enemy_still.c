/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_still.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:38:02 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 10:02:53 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	enemy_still(t_en *en, t_cub *cub)
{
	set_en_img_angle(en, cub);
	en->time += cub->time;
	if (en->time / 500 > 0)
	{
		if (en->sprite == 0 || en->sprite == en->nb_sprites - 1)
			en->sprite = en->nb_runspr;
		else
			en->sprite++;
		en->img = cub->sprites[en->img_dir][en->sprite];
		en->time = 0;
	}
}
