/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:26:45 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/12 12:14:40 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

int	get_door_index(t_door *d, int y, int x)
{
	int	i;

	i = 0;
	while (d[i].open != -1)
	{
		if (d[i].y == y && d[i].x == x)
			return (i);
		i++;
	}
	return (-1);
}

int	check_direction(t_cub *cub, int y, int x)
{
	int	i;

	if (cub->map[y][x] != '1')
		return (1);
	i = get_door_index(cub->doors, y, x);
	if (i != -1 && cub->doors[i].open == 1)
		return (1);
	return (0);
}
