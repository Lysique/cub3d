/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:02:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/21 12:09:10 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

void	srcs_put_my_pixel(t_img img, int y, int x, unsigned int color)
{
	char	*dst;

	dst = img.addr + (y * img.sizel + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	fill_img(t_img img, t_img tmp)
{
	int	y;
	int	x;
	unsigned int	color;
	float	tex_x;
	float	tex_y;

	y = 0;
	tex_y = 0;
	while (y < tmp.h)
	{
		x = 0;
		tex_x = 0;
		while (x < tmp.w)
		{
			color = get_texture_color(img, (int)tex_y, (int)tex_x);
			srcs_put_my_pixel(tmp, y, x, color);
			tex_x += (float)img.w / (float)tmp.w;
			x++;
		}
		tex_y += (float)img.h / (float)tmp.h;
		y++;
	}
}

void	resize_my_imgs(t_cub *cub, t_img *imgs, int h, int w)
{
	int i;
	t_img tmp;

	i = 0;
	while (imgs[i].img)
	{
		tmp.img = mlx_new_image(cub->mlx.mlx, w, h);
		tmp.h = h;
		tmp.w = w;
		tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp,
				&tmp.sizel, &tmp.endian);
		fill_img(imgs[i], tmp);
		mlx_destroy_image(cub->mlx.mlx, imgs[i].img);
		imgs[i] = tmp;
		i++;
	}
}

void	img_resize(t_cub *cub)
{
	resize_my_imgs(cub, cub->sprites[SHOTGUN], cub->sprites[SHOTGUN][0].h * 2.5,
		cub->sprites[SHOTGUN][0].w * 2.5);
	resize_my_imgs(cub, cub->sprites[MACHINEGUN], cub->sprites[MACHINEGUN][0].h * 2.5,
		cub->sprites[MACHINEGUN][0].w * 2.5);
	resize_my_imgs(cub, cub->sprites[MENUBAR], 200, 1690);
	resize_my_imgs(cub, cub->sprites[MAPBAR], 235, 235);
}
