/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shaders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:51:57 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 13:05:20 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

void	create_shader(t_img *img, t_cub *cub, unsigned int color)
{
	int		i;
	int		j;
	t_img	new;

	i = -1;
	new.img = mlx_new_image(cub->mlx.mlx, WIN_W, WIN_H);
	if (!new.img)
		error_manager(IMG_ERROR);
	new.addr = mlx_get_data_addr(new.img, &new.bpp, &new.sizel, &new.endian);
	while (++i < WIN_W)
	{
		j = -1;
		while (++j < WIN_H)
			srcs_put_my_pixel(new, j, i, color);
	}
	*img = new;
}

void	create_shaders(t_img *img, t_cub *cub)
{
	int	i;

	i = 0;
	create_shader(&img[i++], cub, 0xE0000000);
	create_shader(&img[i++], cub, 0xD0000000);
	create_shader(&img[i++], cub, 0xC0000000);
	create_shader(&img[i++], cub, 0xB0000000);
	create_shader(&img[i++], cub, 0xA0000000);
	create_shader(&img[i++], cub, 0x90000000);
	create_shader(&img[i++], cub, 0x80000000);
	create_shader(&img[i++], cub, 0x70000000);
	create_shader(&img[i++], cub, 0x60000000);
	create_shader(&img[i++], cub, 0x50000000);
	create_shader(&img[i++], cub, 0xE0FF0000);
}
