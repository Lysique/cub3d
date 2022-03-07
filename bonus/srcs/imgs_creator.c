/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:02:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 15:56:54 by tamighi          ###   ########.fr       */
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

	i = -1;
	while (++i < nb_imgs)
	{
		path = imgs_join(text, i + 1, ".xpm");
		imgs[i].img = mlx_xpm_file_to_image(cub->mlx.mlx,
				path, &imgs[i].w, &imgs[i].h);
		free(path);
		if (!imgs[i].img)
			error_manager(IMG_ERROR);
		imgs[i].addr = mlx_get_data_addr(imgs[i].img, &imgs[i].bpp,
				&imgs[i].sizel, &imgs[i].endian);
	}
	imgs[i].img = 0;
}

void	imgs_creator3(t_cub *cub)
{
	create_img("sprites/ennemi_nu/en1_NW", 9, cub->sprites[EN1_NW], cub);
	create_img("sprites/ennemi_nu/en1_mort", 9, cub->sprites[EN1_DEAD], cub);
	create_img("sprites/ennemi_nu/en1_atk", 3, cub->sprites[EN1_ATK], cub);
	create_img("sprites/barre_menu/menubar", 1, cub->sprites[MAPBAR], cub);
	create_img("sprites/bouton/bouton", 5, cub->sprites[BUTTONS], cub);
	create_img("sprites/medkit/Medkit", 1, cub->sprites[MEDKIT], cub);
}

void	imgs_creator2(t_cub *cub)
{
	create_img("sprites/police/chiffre", 10, cub->sprites[CHIFFRE], cub);
	create_img("sprites/police/alphabet", 26, cub->sprites[ALPHA], cub);
	create_img("sprites/police/ponct", 9, cub->sprites[PONCT], cub);
	create_img("sprites/portrait/portrait", 8, cub->sprites[PORTRAIT], cub);
	create_img("sprites/text_map/text_map", 4, cub->sprites[IMG_MAP], cub);
	create_img("sprites/ennemi/en_S", 6, cub->sprites[EN2_S], cub);
	create_img("sprites/ennemi/en_N", 6, cub->sprites[EN2_N], cub);
	create_img("sprites/ennemi/en_E", 6, cub->sprites[EN2_E], cub);
	create_img("sprites/ennemi/en_W", 6, cub->sprites[EN2_W], cub);
	create_img("sprites/ennemi/en_SE", 6, cub->sprites[EN2_SE], cub);
	create_img("sprites/ennemi/en_SW", 6, cub->sprites[EN2_SW], cub);
	create_img("sprites/ennemi/en_NE", 6, cub->sprites[EN2_NE], cub);
	create_img("sprites/ennemi/en_NW", 6, cub->sprites[EN2_NW], cub);
	create_img("sprites/ennemi/en_mort", 7, cub->sprites[EN2_DEAD], cub);
	create_img("sprites/ennemi/en_atk", 2, cub->sprites[EN2_ATK], cub);
	create_img("sprites/robot/rob_S", 6, cub->sprites[EN3_S], cub);
	create_img("sprites/robot/rob_N", 6, cub->sprites[EN3_N], cub);
	create_img("sprites/robot/rob_E", 6, cub->sprites[EN3_E], cub);
	create_img("sprites/robot/rob_W", 6, cub->sprites[EN3_W], cub);
	create_img("sprites/robot/rob_SE", 6, cub->sprites[EN3_SE], cub);
	create_img("sprites/robot/rob_SW", 6, cub->sprites[EN3_SW], cub);
	create_img("sprites/robot/rob_NE", 6, cub->sprites[EN3_NE], cub);
	create_img("sprites/robot/rob_NW", 6, cub->sprites[EN3_NW], cub);
	create_img("sprites/explosion/explosion", 29, cub->sprites[I_MISS], cub);
	create_img("sprites/barre_menu/menu", 4, cub->sprites[I_MENU], cub);
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
	create_img("sprites/ennemi_nu/en1_S", 9, cub->sprites[EN1_S], cub);
	create_img("sprites/ennemi_nu/en1_N", 9, cub->sprites[EN1_N], cub);
	create_img("sprites/ennemi_nu/en1_E", 9, cub->sprites[EN1_E], cub);
	create_img("sprites/ennemi_nu/en1_W", 9, cub->sprites[EN1_W], cub);
	create_img("sprites/ennemi_nu/en1_SE", 9, cub->sprites[EN1_SE], cub);
	create_img("sprites/ennemi_nu/en1_SW", 9, cub->sprites[EN1_SW], cub);
	create_img("sprites/ennemi_nu/en1_NE", 9, cub->sprites[EN1_NE], cub);
	imgs_creator2(cub);
	imgs_creator3(cub);
	img_resize(cub);
	create_menu_imgs(cub->sprites[I_MENU], cub);
	create_shaders(cub->sprites[I_SHADERS], cub);
}
