/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:46:21 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 12:26:48 by tamighi          ###   ########.fr       */
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

void	enemy_attack(t_en *en, t_cub *cub)
{
	if (cub->player.life > 0 && en->time == 0)
		cub->player.life -= 1;
	en->time += cub->time;
	if (en->time / 300 < 1)
		en->img = cub->sprites[EN1_S][5];
	else if (en->time / 300 < 2)
		en->img = cub->sprites[EN1_DEAD][0];
	else if (en->time / 300 < 3)
		en->img = cub->sprites[EN1_DEAD][1];
	else if (en->time / 300 < 5)
	{
		en->time = 0;
		en->action = E_STILL;
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
	set_enemy_angle(en, cub, (int)en->y, (int)en->x);
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

void	enemy_die(t_en *en, t_cub *cub)
{
	en->time += cub->time;
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

void	en_action_reset(t_en *en, int action)
{
	if (en->action != action)
	{
		en->action = action;
		en->time = 0;
		en->sprite = 0;
	}
}

void	set_enemy_action(t_en *en, t_cub *cub)
{
	float	d_x;
	float	d_y;
	float	dist;

	d_x = en->x - cub->player.x;
	d_y = en->y - cub->player.y; 
	dist = sqrtf(d_x * d_x + d_y * d_y);
	if (en->life <= 0)
		en_action_reset(en, E_DIE);
	else if (en->action == E_ATTACK || dist <= en->atk_range)
		en_action_reset(en, E_ATTACK);
//	else if (en->life < en->max_life && cub->map_dist[(int)en->y][(int)en->x] != INT_MAX)
//		en_action_reset(en, E_CHASE);
	else if (cub->map_dist[(int)en->y][(int)en->x] <= en->aggro_range)
		en_action_reset(en, E_CHASE);
	else
		en_action_reset(en, E_STILL);
}

void	manage_ennemy(t_en *en, t_cub *cub)
{
	set_enemy_action(en, cub);
	if (en->action == E_STILL)
		enemy_still(en, cub);
	else if (en->action == E_CHASE)
		enemy_move(en, cub);
	else if (en->action == E_ATTACK)
		enemy_attack(en, cub);
	else if (en->action == E_DIE)
		enemy_die(en, cub);
}

void	enemy_manager(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->en[++i].action != -1)
	{
		if (cub->en[i].action == E_DEAD)
			continue ;
		manage_ennemy(&cub->en[i], cub);
	}
}
