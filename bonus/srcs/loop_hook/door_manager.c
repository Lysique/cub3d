/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:06:38 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/09 09:16:24 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	animate_door(t_door *d, t_time time)
{
	d->time += time;
	if (d->time / 1000 > 1)
	{
		d->time -= 1000;
		d->sprite += d->is_moving;
	}
	if ((d->sprite == 0 && d->is_moving == -1)
		|| (d->sprite == 3 && d->is_moving == 1))
	{
		d->is_moving = 0;
		d->time = 0;
	}
}

void	door_animation_manager(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->doors[i].open != -1)
	{
		if (cub->doors[i].is_moving)
			animate_door(&cub->doors[i], cub->time);
		i++;
	}
}

void	ft_gardian_of_the_keys(t_cub *cub)
{
	float	ang;
	float	x;
	float	y;
	int		i;
	float	k;

	if (cub->key.door_p != 1)
		return ;
	ang = cub->player.angle;
	k = 1.1;
	i = -1;
	while (i == -1 && k < DOOR_REACH)
	{
		y = cub->player.y + sin(ang * -1) * k;
		x = cub->player.x + cos(ang) * k;
		k += 0.1;
		i = get_door_index(cub->doors, y, x);
	}
	if (i != -1 && cub->doors[i].is_moving == 0)
	{
		if (cub->doors[i].open == 0)
		{
			cub->doors[i].open = 1;
			cub->doors[i].is_moving = 1;
		}
		else
		{
			cub->doors[i].open = 0;
			cub->doors[i].is_moving = -1;
		}
	}
	cub->key.door_p = 0;
}

void	door_manager(t_cub *cub)
{
	static t_time	time = 0;

	if (time == 0)
		time = get_time();
	cub->time = get_time() - time;
	ft_gardian_of_the_keys(cub);
	door_animation_manager(cub);
}
