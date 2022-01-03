/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:34:19 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/03 08:49:58 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	blackhole_display(t_cub *cub, int x, int y)
{
	int	pix_x;
	int	pix_y;

	pix_x = (x - (cub->player.x - (5 * UNIT))) / 10;
	pix_y = (y - (cub->player.y - (5 * UNIT))) / 10;
	while (pix_x < MINI)
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, pix_x++, pix_y, 0x00FC7462);
}

void	map_display(t_cub *cub, int x, int y)
{
	int	pix_x;
	int	pix_y;

	pix_x = (x - (cub->player.x - (5 * UNIT))) / 10;
	pix_y = (y - (cub->player.y - (5 * UNIT))) / 10;
	while (x < 0)
	{
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, pix_x++, pix_y, 0x00FC7462);
		x += (1 * UNIT) / (MINI / 10);
	}
	while (cub->map[y / UNIT][x / UNIT] && pix_x < MINI)
	{
		if (cub->map[y / UNIT][x / UNIT] == '1')
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, pix_x++, pix_y,
				0x00000000);
		else
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, pix_x++, pix_y,
				0x00FFFFFF);
		x += (1 * UNIT) / (MINI / 10);
	}
	while (pix_x < MINI)
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, pix_x++, pix_y, 0x00FC7462);
}

void	magic_displayer(t_cub *cub, int x, int y)
{
	while (y < 0)
	{
		blackhole_display(cub, x, y);
		y += (1 * UNIT) / (MINI / 10);
	}
	while (cub->map[y / UNIT] && y < cub->player.y + 5 * UNIT)
	{
		map_display(cub, x, y);
		y += (1 * UNIT) / (MINI / 10);
	}
	while (y < cub->player.y + 5 * UNIT)
	{
		blackhole_display(cub, x, y);
		y += (1 * UNIT) / (MINI / 10);
	}
}

void	display_map(t_cub *cub)
{
	int	y;
	int	x;

	y = cub->player.y - UNIT * 5;
	x = cub->player.x - UNIT * 5;
	magic_displayer(cub, x, y);
}
