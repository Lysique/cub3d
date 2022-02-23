/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:46:21 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/23 15:42:12 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	set_enemy_image(t_en *en, t_cub *cub)
{
	en->time += cub->time;
	if (en->time < 100)
		return ;
	en->time = 0;
	if (en->action == E_CHASE || en->action == E_DAMAGED)
	{
		if (en->sprite > 5)
			en->sprite = 0;
		en->img = cub->sprites[en->img_dir][en->sprite];
		en->sprite++;
	}

}

void	enemy_attack(t_en *en, t_cub *cub)
{
	if (cub->player.life > 0 && en->time == 0)
		cub->player.life -= 1;
	if (en->time > 1000)
	{
		en->time = 0;
		en->action = E_STILL;
	}
	else
		en->time += cub->time;
}	

void	enemy_move(t_en *en, t_cub *cub)
{
	en->x += cos(en->angle) * 0.05;
	en->y += sin(en->angle) * -0.05;
	set_enemy_image(en, cub);
}

void	set_en_img_angle(t_en *en, t_cub *cub)
{
	(void)en;
	(void)cub;
}

void	set_en_angle2(t_en *en, t_cub *cub, int y, int x)
{
	if (cub->map_dist[y][x + 1] != -1 && cub->map_dist[y][x + 1] < cub->map_dist[y][x])
		en->angle = 2 * PI - en->angle / 2;
	else if (cub->map_dist[y][x - 1] != -1 && cub->map_dist[y][x - 1] < cub->map_dist[y][x])
		en->angle = PI + en->angle / 2;
	else
	{
		if (en->x - floor(en->x) > 0.8)
			en->angle = PI + en->angle / 2;
		else if (en->x - floor(en->x) < 0.2)
			en->angle = 2 * PI - en->angle / 2;
		else
			en->angle -= PI;
	}
}

void	set_en_angle(t_en *en, t_cub *cub, int y, int x)
{
	if (cub->map_dist[y + 1][x] != -1 && cub->map_dist[y + 1][x] < cub->map_dist[y][x])
		en->angle = 3 * PI / 2;
	else if (cub->map_dist[y - 1][x] != -1 && cub->map_dist[y - 1][x] < cub->map_dist[y][x])
		en->angle = PI / 2;
	else
	{
		if (en->y - floor(en->y) > 0.8)
			en->angle = PI / 2;
		else if (en->y - floor(en->y) < 0.2)
			en->angle = 3 * PI / 2;
		else
			en->angle = PI;
	}
	en->angle -= PI;
	set_en_angle2(en, cub, y, x);
	set_en_img_angle(en, cub);
}

void	enemy_take_a_walk(t_en *en, t_cub *cub)
{
	if (en->life != ENNU_LIFE)
	{
		en->action = E_DAMAGED;
		en->time = 0;
		return ;
	}
	en->time += cub->time;
	if (en->time < 500)
		return ;
	if (en->sprite == 0 || en->sprite == 8)
		en->sprite = 7;
	else
		en->sprite++;
	en->img = cub->sprites[en->img_dir][en->sprite];
	en->time = 0;
}

void	enemy_die(t_en *en, t_cub *cub)
{
	en->time += cub->time;
	if (en->time > 200)
	{
		en->img = cub->sprites[EN1_DEAD][en->sprite];
		if (en->sprite == 3)
			en->offset = 300;
		else if (en->sprite == 4)
			en->offset = 400;
		else if (en->sprite == 5)
			en->offset = 500;
		en->time = 1;
		en->sprite++;
		if (en->sprite == 9)
			en->action = E_DEAD;
		en->time = 0;
	}
	en->time += cub->time;
}

void	en_action_reset(t_en *en, int action)
{
	if (en->action == action)
		return ;
	en->action = action;
	en->time = 0;
	en->sprite = 0;
}

void	set_en_action(t_en *en, t_cub *cub)
{
	float	d_x;
	float	d_y;

	d_x = en->x - cub->player.x;
	d_y = en->y - cub->player.y;
	if (en->life <= 0)
		en_action_reset(en, E_DIE);
	else if (en->action == E_ATTACK || sqrtf(d_x * d_x + d_y * d_y) < 1)
		en_action_reset(en, E_ATTACK);
	else if (en->action == E_DAMAGED && cub->map_dist[(int)en->y][(int)en->x] != INT_MAX)
		en_action_reset(en, E_DAMAGED);
	else if (cub->map_dist[(int)en->y][(int)en->x] <= 10)
		en_action_reset(en, E_CHASE);
	else
		en_action_reset(en, E_STILL);
}

void	manage_ennemy(t_en *en, t_cub *cub)
{
	if (en->action == E_DEAD)
		return ;
	set_en_action(en, cub);
	if (en->action == E_STILL)
		enemy_take_a_walk(en, cub);
	else if (en->action == E_CHASE || en->action == E_DAMAGED)
	{
		set_en_angle(en, cub, (int)en->y, (int)en->x);
		enemy_move(en, cub);
	}
	else if (en->action == E_ATTACK)
		enemy_attack(en, cub);
	else if (en->action == E_DIE)
		enemy_die(en, cub);
}

void	ennemy_manager(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->en[++i].action != -1)
		manage_ennemy(&cub->en[i], cub);
}
