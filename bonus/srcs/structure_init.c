/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:21:16 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/10 11:21:16 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

void	music_init(void)
{
	if (access("music/son_ambiance.mp3", F_OK) < 0)
		error_manager(MUSIC_NOT_FOUND);
	system("afplay music/son_ambiance.mp3 &>/dev/null &");
}

void	mlx_variables_init(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
		error_manager(MLX_ERROR);
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIN_W, WIN_H, "cub3d");
	if (!cub->mlx.win)
		error_manager(MLX_ERROR);
}

void	var_init(t_cub *cub)
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
	cub->gun[0].sprite = 0;
	cub->gun[0].bullets = 2;
	cub->gun[0].nb_sprites = 12;
	cub->gun[0].nb_spr_shoot = 1;
	cub->gun[0].time = 0;
	cub->gun[0].shooting = 0;
	cub->gun[0].reloading = 0;
	cub->gun[1].sprite = 0;
	cub->gun[1].bullets = 50;
	cub->gun[1].nb_sprites = 13;
	cub->gun[1].nb_spr_shoot = 2;
	cub->gun[1].shooting = 0;
	cub->gun[1].reloading = 0;
}

void	imgs_init(t_cub *cub)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	cub->display.img = 0;
	while (i != 0)
		cub->textures[--i].img = 0;
	while (i < NB_SPR)
	{
		while (j < MAX_SPR)
			cub->sprites[i][j++].img = 0;
		j = 0;
		i++;
	}
}

void	structure_init(t_cub *cub)
{
	set_cubptr(cub);
	var_init(cub);
	imgs_init(cub);
	music_init();
	mlx_variables_init(cub);
	imgs_creator(cub);
}
