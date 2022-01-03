/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:48:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 10:17:16 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

int	key_hook(int key, void *param)
{
	t_cub *cub;

	cub = (t_cub *)param;
	if (key == 53)
		free_and_exit(cub, "Exit\n", 0);
	return (0);
}
