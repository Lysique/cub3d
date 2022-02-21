/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 13:01:00 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

int	loop_hook(t_cub *cub)
{
	static int	i = 0;
	static t_time	time = 0;

	cub->time = get_time() - time;

	if (++i / 200 == 0)
		return (0);
	else
		i = 0;
	time = get_time();
	door_manager(cub);
	player_manager(cub);
	gun_manager(cub);
	ennemy_manager(cub);
	display(cub);
	return (0);
}
