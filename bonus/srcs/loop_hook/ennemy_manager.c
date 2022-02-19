/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 14:46:21 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/19 14:50:32 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	manage_ennemy(t_en *en, t_cub *cub)
{
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
