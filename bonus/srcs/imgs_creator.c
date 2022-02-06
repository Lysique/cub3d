/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:02:11 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/06 14:17:59 by tamighi          ###   ########.fr       */
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
	while (nb / length > 10)
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
		imgs[i].img = mlx_xpm_file_to_image(cub->mlx.mlx, path, &imgs[i].w, &imgs[i].h);
		free(path);
		if (!imgs[i].img)
			error_manager(IMG_ERROR);
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
	create_img("sprites/life/barre_eclair", 6, cub->sprites[LIFE], cub);
}
