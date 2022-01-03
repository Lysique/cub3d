/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:48:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 14:50:40 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

int	key_press(int key, void *param)
{
	t_cub *cub;

	cub = (t_cub *)param;
	if (key == 53)
		free_and_exit(cub, "Exit\n", 0);
	if (key == 2)
		cub->key.d = 1;
	else if (key == 0)
		cub->key.a = 1;
	else if (key == 1)
		cub->key.s = 1;
	else if (key == 13)
		cub->key.w = 1;
	else if (key == 123)
		cub->key.left = 1;
	else if (key == 124)
		cub->key.right = 1;
	return (0);
}
