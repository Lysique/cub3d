/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:43:21 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/27 10:43:43 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	order_enemies(t_cub *cub)
{
	int		i;
	float	dist;
	float	dist2;
	t_en	en;

	i = -1;
	dist = -1;
	while (cub->en[++i].action != -1)
	{
		dist2 = (cub->player.x - cub->en[i].x) * (cub->player.x - cub->en[i].x)
			+ (cub->player.y - cub->en[i].y) * (cub->player.y - cub->en[i].y);
		if (dist != -1 && dist2 > dist)
		{
			dist = -1;
			en = cub->en[i - 1];
			cub->en[i - 1] = cub->en[i];
			cub->en[i] = en;
			i = -1;
		}
		else
			dist = dist2;
	}
}
