/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:50:58 by tuytters          #+#    #+#             */
/*   Updated: 2022/02/26 16:03:48 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

void	mouse_release_game(int key, t_cub *cub)
{
	if (key == 1)
		cub->key.shoot_r = 1;
}

int	mouse_release(int key, int x, int y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	(void) x;
	(void) y;
	if (cub->game_state == GAME)
		mouse_release_game(key, cub);
	return (0);
}
