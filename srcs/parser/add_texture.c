/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:30:59 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/31 16:07:41 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	add_img(char *texture, t_cub *cub, int index)
{
	t_img	img;

	img = cub->textures[index];
	img.img = mlx_xpm_file_to_image(cub->mlx.mlx, texture, &img.w, &img.h);
	if (!img.img)
		parser_error(XPM_ERROR, texture);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.sizel, &img.endian);
	cub->textures[index] = img;
}

int	add_rgb_part(char *texture, int *i, int *color, int commas)
{
	int	color_num;

	color_num = 0;
	while (texture[*i] && texture[*i] != ',' && !ft_isspace(texture[*i]))
	{
		if ((texture[*i] < 0 || texture[*i] > 9))
			return (-1);
		color_num += texture[*i] - '0';
		(*i)++;
	}
	if (texture[*i] == ',')
		(*i)++;
	if (commas == 0)
		*color += color_num * 256 * 256;
	else if (commas == 1)
		*color += color_num * 256;
	else
		*color += color_num;
	return (0);
}
void	add_rgb(char *texture, t_cub *cub, int index)
{
	unsigned int	color;
	int				i;
	int				commas;

	color = 0;
	i = 0;
	commas = 0;
	while (texture[i] && !ft_isspace(texture[i]))
	{
		if (add_rgb_part(texture, &i, commas) == -1)
			return ;
	}
}

void	add_texture(char *texture, t_cub *cub, int index)
{
	add_rgb(texture, cub, index);
	if (!cub->textures[index].img)
		add_img(texture, cub, index);
}

