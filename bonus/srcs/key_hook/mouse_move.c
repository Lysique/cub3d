/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:20:33 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 14:37:37 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

int	mouse_move(int x, int y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	(void)y;
	if (cub->game_state == GAME)
	{
		cub->mouse.x = x;
		mlx_mouse_move(cub->mlx.win, WIN_W / 2, WIN_H / 2);
	}
	return (0);
}
