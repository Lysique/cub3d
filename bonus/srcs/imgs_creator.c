/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:02:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/14 12:18:54 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/srcs.h"

char	*imgs_join(char *path, int nb, char *xpm)
{
	char	*new;
	int		i;
	int		length;

	new = malloc(ft_strlen(path) + ft_strlen(xpm) + 3);
	if (!new)
		error_manager(MALLOC_ERROR);
	i = 0;
	length = 1;
	while (*path)
		new[i++] = *(path++);
	while (nb / length >= 10)
		length *= 10;
	while (length)
	{
		new[i++] = nb / length + '0';
		nb = nb % length;
		length = length / 10;
	}
	while (*xpm)
		new[i++] = *(xpm++);
	new[i] = 0;
	return (new);
}

void	create_img(char *text, int nb_imgs, t_img *imgs, t_cub *cub)
{
	char	*path;
	int		i;

	i = 0;
	while (i < nb_imgs)
	{
		path = imgs_join(text, i + 1, ".xpm");
		imgs[i].img = mlx_xpm_file_to_image(cub->mlx.mlx,
				path, &imgs[i].w, &imgs[i].h);
		free(path);
		if (!imgs[i].img)
			error_manager(IMG_ERROR);
		imgs[i].addr = mlx_get_data_addr(imgs[i].img, &imgs[i].bpp,
				&imgs[i].sizel, &imgs[i].endian);
		i++;
	}
	imgs[i].img = 0;
}

void	imgs_creator(t_cub *cub)
{
	cub->display.img = mlx_new_image(cub->mlx.mlx, WIN_W, WIN_H);
	if (!cub->display.img)
		error_manager(IMG_ERROR);
	cub->display.addr = mlx_get_data_addr(cub->display.img,
			&cub->display.bpp, &cub->display.sizel, &cub->display.endian);
	cub->display.w = WIN_W;
	cub->display.h = WIN_H;
	create_img("sprites/life/barre_eclair", 6, cub->sprites[LIFE], cub);
	create_img("sprites/door/door", 4, cub->sprites[DOOR], cub);
	create_img("sprites/pompe/pompe", 12, cub->sprites[SHOTGUN], cub);
	create_img("sprites/mitrailleuse/mitrailleuse", 13,
		cub->sprites[MACHINEGUN], cub);
	create_img("sprites/barre_menu/menubar", 1, cub->sprites[MENUBAR], cub);
	create_img("sprites/ennemi_nu/en1_S", 1, cub->sprites[NAKED_EN], cub);
	create_img("sprites/barre_menu/menubar", 1, cub->sprites[MAPBAR], cub);
	create_img("sprites/police/chiffre", 10, cub->sprites[CHIFFRE], cub);
	create_img("sprites/police/alphabet", 26, cub->sprites[ALPHA], cub);
	create_img("sprites/police/ponct", 9, cub->sprites[PONCT], cub);
	img_resize(cub);
}
