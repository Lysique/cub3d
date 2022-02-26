/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:20:02 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 14:34:30 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	set_en_move_image(t_en *en, t_cub *cub)
{
	en->time += cub->time;
	if (en->time / en->run_spr_speed > 0)
	{
		if (en->sprite > en->nb_runspr - 1)
			en->sprite = 0;
		en->img = cub->sprites[en->img_dir][en->sprite];
		en->sprite++;
		en->time = 0;
	}
}

void	check_enemy_path(t_en *en, t_cub *cub, int *y, int *x)
{
	int		i;
	float	dist;

	i = -1;
	dist = en->run_speed * cub->time;
	while (cub->en[++i].action != -1)
	{
		if (cub->en[i].life <= 0)
			continue ;
		if (cub->en[i].x == en->x && cub->en[i].y == en->y)
			continue ;
		if (en->x + cos(en->angle) * dist > cub->en[i].x - cub->en[i].hbox
			&& en->x + cos(en->angle) * dist < cub->en[i].x + cub->en[i].hbox
			&& en->y > cub->en[i].y - cub->en[i].hbox
			&& en->y < cub->en[i].y + cub->en[i].hbox)
			*x = 0;
		if (en->y + sin(en->angle) * -dist > cub->en[i].y - cub->en[i].hbox
			&& en->y + sin(en->angle) * -dist < cub->en[i].y + cub->en[i].hbox
			&& en->x > cub->en[i].x - cub->en[i].hbox
			&& en->x < cub->en[i].x + cub->en[i].hbox)
			*y = 0;
	}
}

void	enemy_move(t_en *en, t_cub *cub)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	set_enemy_angle(en, cub);
	check_enemy_path(en, cub, &y, &x);
	set_en_img_angle(en, cub);
	if (x)
		en->x += cos(en->angle) * (en->run_speed * cub->time);
	if (y)
		en->y += -sin(en->angle) * (en->run_speed * cub->time);
	if ((!x || (cos(en->angle) > -0.1 && cos(en->angle) < 0.01))
		&& (!y || (sin(en->angle) > -0.01 && sin(en->angle) < 0.01)))
		en->img = cub->sprites[en->img_dir][7];
	else
		set_en_move_image(en, cub);
}
