/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missile_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 07:36:51 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 10:26:52 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	destroy_door(t_cub *cub, int i)
{
	int	j;

	j = 0;
	cub->map[cub->doors[i].y][cub->doors[i].x] = '0';
	cub->map_dist[cub->doors[i].y][cub->doors[i].x] = INT_MAX;
	while (cub->doors[j].open != -1)
		j++;
	j--;
	cub->doors[i].open = cub->doors[j].open;
	cub->doors[i].is_moving = cub->doors[j].is_moving;
	cub->doors[i].x = cub->doors[j].x;
	cub->doors[i].y = cub->doors[j].y;
	cub->doors[i].sprite = cub->doors[j].sprite;
	cub->doors[j].open = -1;	
	j = 0;
	map_dist_manager(cub);
}

void	missile_explode(t_en *en, t_cub *cub)
{
	int	i;

	if (en->miss.active == 2)
	{
		en->miss.active = 3;
		i = get_door_index(cub->doors, (int)en->miss.y_dest, (int)en->miss.x_dest);
		if (i != -1)
			destroy_door(cub, i);
		else if (cub->player.x - 1. < en->miss.x && cub->player.x + 1. > en->miss.x
			&& cub->player.y - 1. < en->miss.y && cub->player.y + 1. > en->miss.y)
			if (cub->player.life > 0)
				cub->player.life--;
	}
	en->miss.time += cub->time;
	if (en->miss.time / MISS_SPR_EXPLODE_SPEED > 0)
	{
		en->miss.img = cub->sprites[I_MISS][en->miss.sprite];
		en->miss.sprite++;
		if (en->miss.sprite == MISS_NB_SPRITES)
		{
			en->miss.sprite = 0;
			en->miss.active = 0;
		}
		en->miss.time = 0;
	}
}

void	missile_keep_going(t_en *en, t_cub *cub)
{
	float	dist;

	en->miss.x += cos(en->miss.angle) * MISS_SPEED * cub->time;
	en->miss.y += sin(en->miss.angle) * -1  * MISS_SPEED * cub->time;
	en->miss.img = cub->sprites[I_MISS][0];
	if (miss_arrived_at_destination(en->miss))
	{
		en->miss.active = 2;
		en->miss.x = en->miss.x_dest;
		en->miss.y = en->miss.y_dest;
	}
	dist = sqrtf((en->miss.x - en->miss.x_dest) * (en->miss.x - en->miss.x_dest)
		+ (en->miss.y - en->miss.y_dest) * (en->miss.y - en->miss.y_dest));
	en->miss.offset = (int)((1. - (float)(dist / en->miss.dist)) * 400);
}

void	missile_manager(t_en *en, t_cub *cub)
{
	if (en->miss.active == 1)
		missile_keep_going(en, cub);
	if (en->miss.active >= 2)
		missile_explode(en, cub);
}
