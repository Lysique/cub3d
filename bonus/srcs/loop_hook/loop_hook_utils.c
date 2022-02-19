/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:26:45 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/17 13:29:50 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

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
