/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emotion_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:02:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/23 15:01:07 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	emotion_manager(t_cub *cub)
{
	if (cub->player.life < 4)
			cub->player.emotion = 4;
	if (cub->player.life < 2)
			cub->player.emotion = 3;
	else
		cub->player.emotion = 1;
	if (cub->action == SHOOTING)
	{
		if (cub->gun_type == 0)
			cub->player.emotion = 5;
		else
			cub->player.emotion = 6;
	}
}
