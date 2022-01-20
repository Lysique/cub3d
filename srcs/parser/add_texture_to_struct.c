/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture_to_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:45:51 by tamighi           #+#    #+#             */
/*   Updated: 2022/01/20 14:33:35 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	textures_check_line(char *line)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (cub3d_isspace(line[i]))
		i++;
	if (line[i] == '1')
		x = texture_error(5, line);
	else if (line[i])
		x = texture_error(6, line);
	return (x);
}

char	*go_to_path(char *line, int index)
{
	int	i;
	int j;
	int	error;

	error = 0;
	if (index < 4)
		i = 2;
	else
		i = 1;
	if (!line[i])
		error = texture_error(2, line);
	else if (!cub3d_isspace(line[i++]))
		error = texture_error(3, line);
	else if (!line[i])
		error = texture_error(2, line);
	while (cub3d_isspace(line[i]))
		i++;
	if (!line[i])
		error = texture_error(2, line);
	j = i;
	while (!cub3d_isspace(line[j]) && line[j])
		j++;
	line[j] = '\0';
	if (error == -1)
		return (0);
	return (&line[i]);
}

int	add_img(char *line, t_cub *cub, int index)
{
	t_img	img;

	img = cub->textures[index];
	if (img.img)
		return (texture_error(1, 0));
	line = go_to_path(line, index);
	if (!line)
		return (-1);
	img.img = mlx_xpm_file_to_image(cub->mlx.mlx, line, &img.w, &img.h);
	if (!img.img)
		return (texture_error(4, line));
	cub->textures[index] = img;
	return (1);
}

int	add_rgb(char *line, t_cub *cub, int index)
{
	return (add_img(line, cub, index));
}

int	add_texture_to_struct(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	if ((++i && cub3d_strcmp("NO", line)) || (++i && cub3d_strcmp("SO", line))
		|| (++i && cub3d_strcmp("WE", line)) || (++i && cub3d_strcmp("EA", line)))
		return (add_img(line, cub, i - 1));
	else if ((++i && cub3d_strcmp("F", line)) || (++i && cub3d_strcmp("C", line)))
		return (add_rgb(line, cub, i - 1));
	else
		return (textures_check_line(line));
}
