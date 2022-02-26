/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:20:02 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 13:20:26 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	set_enemy_image(t_en *en, t_cub *cub)
{
	en->time += cub->time;
	if (en->time < EN1_RUN_SPR_SPEED)
		return ;
	en->time = 0;
	if (en->action == E_CHASE)
	{
		if (en->sprite > en->nb_runspr - 1)
			en->sprite = 0;
		en->img = cub->sprites[en->img_dir][en->sprite];
		en->sprite++;
	}
}

void	enemy_move(t_en *en, t_cub *cub)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 1;
	y = 1;
	set_enemy_angle(en, cub);
	set_en_img_angle(en, cub);
	while (cub->en[++i].action != -1)
	{
		if (cub->en[i].life <= 0 || (cub->en[i].x == en->x && cub->en[i].y == en->y))
			continue ;
		if (en->x + cos(en->angle) * en->run_speed > cub->en[i].x - cub->en[i].hbox
			&& en->x + cos(en->angle) * en->run_speed < cub->en[i].x + cub->en[i].hbox
			&& en->y > cub->en[i].y - cub->en[i].hbox
			&& en->y < cub->en[i].y + cub->en[i].hbox)
			x = 0;
		if (en->y + sin(en->angle) * en->run_speed * -1 > cub->en[i].y - cub->en[i].hbox
			&& en->y + sin(en->angle) * en->run_speed * -1 < cub->en[i].y + cub->en[i].hbox
			&& en->x > cub->en[i].x - cub->en[i].hbox
			&& en->x < cub->en[i].x + cub->en[i].hbox)
			y = 0;
	}
	if (x)
		en->x += cos(en->angle) * en->run_speed;
	if (y)
		en->y += sin(en->angle) * en->run_speed * -1;
	if ((!x || (cos(en->angle) > -0.1 && cos(en->angle) < 0.01))
		&& (!y || (sin(en->angle) > -0.01 && sin(en->angle) < 0.01)))
		en->img = cub->sprites[en->img_dir][7];
	else	
		set_enemy_image(en, cub);
}
