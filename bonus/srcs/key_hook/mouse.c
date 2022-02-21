/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:59:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/14 10:50:19 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

int	mouse_press(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	error_manager(EXOK);
	return (0);
}

float	angle(float angle)
{
	if (angle < 0)
		return (angle + 2.0 * PI);
	else if (angle > 2.0 * PI)
		return (angle - 2.0 * PI);
	return (angle);
}

int	mouse_move(int x, int y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	(void)y;
	if (x > WIN_W / 3 + WIN_W / 8 && x < WIN_W / 3 * 2 - WIN_W / 8)
		cub->mouse.x = WIN_W / 2;
	else
		cub->mouse.x = x;
	return (0);
}

int	mouse_click(int key, int x, int y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	(void) x;
	(void) y;
	if (key == 1 && cub->key.shoot_r == 1)
	{
		cub->key.shoot_r = 0;
		cub->key.shoot_p = 1;
	}
	else if (key == 3 || key == 4 || key == 5)
		cub->key.swap_gun = 1;
	else if (key == 2)
		cub->key.reload = 1;
	return (0);
}
