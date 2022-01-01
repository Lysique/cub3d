/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture_to_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:45:51 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/01 13:41:36 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	*go_to_path(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ' ' && line[i])
		i++;
	while (line[i] == ' ' || line[i] == '	')
		i++;
	return (&line[i]);
}

int	add_img(char *line, t_cub *cub, int nb)
{
	t_img	img;

	img = cub->textures[nb - 1];
	if (img.img)
		return (-1);
	line = go_to_path(line);
	img.img = mlx_xpm_file_to_image(cub->mlx.mlx, line, &img.w, &img.h);
	if (!img.img)
		return (-1);
	cub->textures[nb - 1] = img;
	return (1);
}

int	add_rgb(char *line, t_cub *cub, int nb)
{
	return (add_img(line, cub, nb));
}

int	add_texture_to_struct(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	if ((++i && ft_strcmp("NO ", line)) || (++i && ft_strcmp("SO ", line)) ||
		(++i && ft_strcmp("WE ", line)) || (++i && ft_strcmp("EA ", line)))
		return (add_img(line, cub, i));
	else if ((++i && ft_strcmp("F ", line)) || (++i && ft_strcmp("C ", line)))
		return (add_rgb(line, cub, i));
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' || line[i] != '	')
			return (-1);
	}
	return (1);
}
