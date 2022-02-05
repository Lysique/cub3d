/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:21:16 by tuytters          #+#    #+#             */
/*   Updated: 2022/02/02 14:31:32 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/loop_hook.h"

void	key_init(t_cub *cub)
{
	cub->key.d = 0;
	cub->key.a = 0;
	cub->key.s = 0;
	cub->key.w = 0;
	cub->key.left = 0;
	cub->key.right = 0;
	cub->mouse.x = WIN_W / 2;
}
