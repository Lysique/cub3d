/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:23:24 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/13 17:50:14 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

void	gun_init(t_cub *cub)
{
	cub->gun[0].sprite = 0;
	cub->gun[0].bullets = SG_BULLETS;
	cub->gun[0].max_bullets = SG_BULLETS;
	cub->gun[0].nb_sprites = 12;
	cub->gun[0].nb_spr_shoot = 1;
	cub->gun[0].time = 0;
	cub->gun[0].status = GS_FREE;
	cub->gun[1].sprite = 0;
	cub->gun[1].bullets = MG_BULLETS;
	cub->gun[1].max_bullets = MG_BULLETS;
	cub->gun[1].nb_sprites = 13;
	cub->gun[1].nb_spr_shoot = 2;
	cub->gun[1].status = GS_FREE;
}

void	variables_init(t_cub *cub)
{
	cub->key.w = 0;
	cub->key.s = 0;
	cub->key.a = 0;
	cub->key.d = 0;
	cub->key.right = 0;
	cub->key.left = 0;
	cub->key.door_r = 1;
	cub->key.door_p = 0;
	cub->key.reload = 0;
	cub->key.shoot_r = 1;
	cub->key.shoot_p = 0;
	cub->key.swap_gun = 0;
	cub->gun_type = 0;
	cub->mouse.x = WIN_W / 2;
	cub->map = 0;
	cub->mlx.mlx = 0;
	cub->mlx.win = 0;
	cub->doors = 0;
	cub->action = FREE_GUN;
	gun_init(cub);
}

