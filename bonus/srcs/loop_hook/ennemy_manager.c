/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:46:21 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 12:53:06 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	ennemy_path(t_en *en, t_cub *cub)
{
	float	delta_x;
	float	delta_y;
	float	add;

	delta_x = (cub->player.x - en->x);
	delta_y = (cub->player.y - en->y);
	add = (fabsf(delta_x) + fabsf(delta_y));
	if (add < 1 || en->life <= 0)
		return ;
	if (abs((int)delta_x) > abs((int)delta_y))
		en->x += 0.05 * (delta_x / add);
	else if (abs((int)delta_x) < abs((int)delta_y))
		en->y += 0.05 * (delta_y / add);
	else
	{
		en->x += 0.05 * (delta_x / add);
		en->y += 0.05 * (delta_y / add);
	}
}

void	manage_ennemy(t_en *en, t_cub *cub)
{
	ennemy_path(en, cub);
	(void)cub;
	(void)en;
}

void	ennemy_manager(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->en[++i].action != -1)
		manage_ennemy(&cub->en[i], cub);
}
