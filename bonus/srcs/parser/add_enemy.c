/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:39:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 12:18:33 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"


void	add_soldier_enemy(t_cub *cub, t_en *en, int j, int i)
{
	en->type = SOLDIER_EN;
	en->x = i + 0.5;
	en->y = j + 0.5;
	en->angle = PI;
	en->action = E_STILL;
	en->sprite = 0;
	en->life = EN2_LIFE;
	en->max_life = EN2_LIFE;
	en->nb_sprites = EN2_NBSPR;
	en->nb_runspr = EN2_NBRUNSPR;
	en->img = cub->sprites[EN2_S][0];
	en->img_dir = EN2_S;
	en->hbox = EN2_HBOX;
	en->time = 0;
	en->atk_range = EN2_ATK_RANGE;
	en->aggro_range = EN2_AGGRO_RANGE;
	en->run_speed = EN2_RUN_SPEED;
	en->run_spr_speed = EN2_RUN_SPR_SPEED;
	en->atk_speed = EN2_ATK_SPEED;
	en->offset = EN2_OFFSET;
	en->div = EN2_DIV;
}


void	add_naked_enemy(t_cub *cub, t_en *en, int j, int i)
{
	en->type = NAKED_EN;
	en->x = i + 0.5;
	en->y = j + 0.5;
	en->angle = PI;
	en->action = E_STILL;
	en->sprite = 0;
	en->time = 0;
	en->life = EN1_LIFE;
	en->max_life = EN1_LIFE;
	en->nb_sprites = EN1_NBSPR;
	en->nb_runspr = EN1_NBRUNSPR;
	en->img = cub->sprites[EN1_S][EN1_NBRUNSPR];
	en->img_dir = EN1_S;
	en->hbox = EN1_HBOX;
	en->atk_range = EN1_ATK_RANGE;
	en->aggro_range = EN1_AGGRO_RANGE;
	en->run_speed = EN1_RUN_SPEED;
	en->run_spr_speed = EN1_RUN_SPR_SPEED;
	en->atk_speed = EN1_ATK_SPEED;
	en->offset = EN1_OFFSET;
	en->div = EN1_DIV;
}

void	add_enemy(t_cub *cub, char c, int j, int i)
{
	int	k;

	k = 0;
	while (cub->en[k].action != -1)
		k++;
	if (c == 'n')
		add_naked_enemy(cub, &cub->en[k], j, i);
	else if (c == 's')
		add_soldier_enemy(cub, &cub->en[k], j, i);
	cub->en[++k].action = -1;
	cub->map[j][i] = '0';
}
