/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:46:21 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 16:37:06 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	manage_ennemy(t_en *en, t_cub *cub)
{
	set_enemy_action(en, cub);
	if (en->action == E_STILL)
		enemy_still(en, cub);
	else if (en->action == E_CHASE)
		enemy_move(en, cub);
	else if (en->action == E_ATTACK || en->action == E_HAS_ATK)
		enemy_attack(en, cub);
	else if (en->action == E_DIE)
		enemy_die(en, cub);
}

void	enemy_manager(t_cub *cub)
{
	int	i;

	i = -1;
	while (cub->en[++i].action != -1)
	{
		if (cub->en[i].type == BOSS_EN)
			if (cub->en[i].miss.active != 0)
				missile_manager(&cub->en[i], cub);
		if (cub->en[i].action == E_DEAD)
			continue ;
		if (cub->en[i].type == BOSS_EN)
			manage_boss(&cub->en[i], cub);
		else
			manage_ennemy(&cub->en[i], cub);
	}
}
