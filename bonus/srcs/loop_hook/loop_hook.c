/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:05:35 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 14:53:56 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

int	loop_hook(t_cub *cub)
{
	static t_time	time = 0;
	static t_time	emo = 0;

	cub->time = get_time() - time;
	time = get_time();
	if (cub->player.emotion != 0)
		emo += cub->time;
	if (emo >= 1000)
	{
		cub->player.emotion = 0;
		emo = 0;
	}
	door_manager(cub);
	player_manager(cub);
	gun_manager(cub);
	ennemy_manager(cub);
	display(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->display.img, 0, 0);
	mlx_do_sync(cub->mlx.mlx);
	return (0);
}
