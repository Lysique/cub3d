/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkits_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:00:33 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 16:03:43 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	mkits_manager(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->mkits[++i].active != -1)
	{
		if (cub->mkits[i].active == 1
			&& (int)cub->player.x == (int)cub->mkits[i].x
			&& (int)cub->player.y == (int)cub->mkits[i].y)
		{
			cub->mkits[i].active = 0;
			cub->player.life = 5;
		}
	}
}
