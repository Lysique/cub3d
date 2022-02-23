/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:26:45 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/23 10:16:55 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

int	check_p_dir(t_cub *cub, float y, float x)
{
	int	i;

	if (cub->map[(int)y][(int)x] != '1')
		return (1);
	i = get_door_index(cub->doors, (int)y, (int)x);
	if (i != -1 && cub->doors[i].open == 1)
		return (1);
	return (0);
}
