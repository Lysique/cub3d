/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:06:38 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 14:21:53 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	animate_door(t_door *d, t_time time)
{
	d->time += time;
	if (d->time / DOOR_FRAME > 0)
	{
		d->time -= DOOR_FRAME;
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

int	looking_for_door(t_cub *cub)
{
	float	ang;
	float	x;
	float	y;
	float	k;
	int		i;

	k = 1;
	i = -1;
	ang = cub->player.angle;
	while (i == -1 && k < DOOR_REACH)
	{
		y = cub->player.y + sin(ang * -1) * k;
		x = cub->player.x + cos(ang) * k;
		k += 0.1;
		i = get_door_index(cub->doors, y, x);
	}
	return (i);
}

void	ft_gardian_of_the_keys(t_cub *cub)
{
	int		i;

	i = looking_for_door(cub);
	if (i != -1 && cub->doors[i].is_moving == 0)
	{
		if (is_en_on_door(cub->doors[i], cub->en))
			return ;
		if (cub->doors[i].open == 0)
		{
			cub->doors[i].open = 1;
			cub->doors[i].is_moving = 1;
			system("afplay -v 0.5 music/ouverture_ascenseur.mp3 &>/dev/null &");
		}
		else
		{
			cub->doors[i].open = 0;
			cub->doors[i].is_moving = -1;
			system("afplay -v 0.5 music/fermeture_ascenseur.mp3 &>/dev/null &");
		}
		map_dist_manager(cub);
	}
	cub->key.door_p = 0;
}

void	door_manager(t_cub *cub)
{
	if (cub->key.door_p == 1)
		ft_gardian_of_the_keys(cub);
	door_animation_manager(cub);
}
