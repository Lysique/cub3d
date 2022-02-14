/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:50:58 by tuytters          #+#    #+#             */
/*   Updated: 2022/02/14 09:51:24 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

int	mouse_release(int key, int x, int y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	(void) x;
	(void) y;
	if (key == 1)
		cub->key.shoot_r = 1;
	return (0);
}
