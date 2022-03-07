/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:42:54 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/07 09:38:47 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	display_gun_sight(t_cub *cub)
{
	int	x;
	int	y;

	x = WIN_W / 2 - 2;
	while (x < WIN_W / 2 + 2)
	{
		y = WIN_H / 2 - 2;
		while (y < WIN_H / 2 + 2)
			put_my_pixel(cub->display, y++, x, RED);
		x++;
	}
}

void	display_gun(t_cub *cub)
{
	int		start_x;
	int		start_y;
	t_img	img;

	img = cub->sprites[cub->gun_type + 2][cub->gun[cub->gun_type].sprite];
	start_x = POS_GUN_X - img.w / 2;
	start_y = POS_GUN_Y - img.h;
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		img.img, start_x, start_y);
	display_gun_sight(cub);
}
