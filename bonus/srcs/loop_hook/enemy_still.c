/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_still.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 09:38:02 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 12:42:56 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	swap_soldier_angle(t_en *en)
{
	if (en->angle < 0.1 && en->angle > -0.1)
		en->angle = PI;
	else
		en->angle = 0;
}

void	soldier_still(t_en *en, t_cub *cub)
{
	float	x;
	float	y;
	float	add;
	float	dist;

	x = en->x;
	y = en->y;
	dist = en->run_speed * cub->time;
	add = cos(en->angle) * (en->hbox + dist);
	if (cub->map[(int)(y)][(int)(x + add)] == '0')
		en->x += add - (en->hbox * cos(en->angle));
	else
		swap_soldier_angle(en);
	if (en->sprite >= en->nb_runspr)
		en->sprite = 0;
	if (en->time / en->run_spr_speed > 0)
	{
		set_en_img_angle(en, cub);
		en->img = cub->sprites[en->img_dir][en->sprite];
		en->sprite++;
		en->time = 0;
	}
}

void	naked_still(t_en *en, t_cub *cub)
{
	if (en->time / 500 > 0)
	{
		set_en_img_angle(en, cub);
		if (en->sprite == 0 || en->sprite == en->nb_sprites - 1)
			en->sprite = en->nb_runspr;
		else
			en->sprite++;
		en->img = cub->sprites[en->img_dir][en->sprite];
		en->time = 0;
	}
}

void	enemy_still(t_en *en, t_cub *cub)
{
	if (en->type == NAKED_EN)
		naked_still(en, cub);
	if (en->type == SOLDIER_EN)
		soldier_still(en, cub);
	en->time += cub->time;
}
