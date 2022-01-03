/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:59:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 14:51:16 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

int	key_release(int key, void *param)
{
	t_cub *cub;

	cub = (t_cub *)param;
	if (key == 2)
		cub->key.d = 0;
	else if (key == 0)
		cub->key.a = 0;
	else if (key == 1)
		cub->key.s = 0;
	else if (key == 13)
		cub->key.w = 0;
	else if (key == 123)
		cub->key.left = 0;
	else if (key == 124)
		cub->key.right = 0;
	return (0);
}
