/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:59:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/12 09:36:01 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

int	key_release(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (key == 100)
		cub->key.d = 0;
	else if (key == 97)
		cub->key.a = 0;
	else if (key == 115)
		cub->key.s = 0;
	else if (key == 119)
		cub->key.w = 0;
	else if (key == 65361)
		cub->key.left = 0;
	else if (key == 65363)
		cub->key.right = 0;
	return (0);
}
